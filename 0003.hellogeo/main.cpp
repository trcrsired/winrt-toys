class App : public winrt::Microsoft::UI::Xaml::ApplicationT<App>
{
  public:
    void OnLaunched(winrt::Microsoft::UI::Xaml::LaunchActivatedEventArgs const &)
    try
    {
        window = winrt::Microsoft::UI::Xaml::Window();
        window.Title(L"Geolocation");

        winrt::hstring hstr;
        try
        {
          using namespace winrt::Windows::Foundation;
          using namespace winrt::Windows::Devices::Geolocation;
          Geolocator geolocator;
          geolocator.DesiredAccuracy(PositionAccuracy::High);
          Geoposition pos = geolocator.GetGeopositionAsync().get();

          auto const &coordinate = pos.Coordinate().Point().Position();
          hstr = ::fast_io::wconcat_winrt_hstring(
            L"Latitude=", coordinate.Latitude,
            L"\nLongitude=", coordinate.Longitude,
            L"\naltitude=", coordinate.Altitude);
        }
        catch (::winrt::hresult_error const &e) {
          hstr = e.message();
        } catch (...) {
          hstr = L"Unknown EH";
        }
        textblock.Text(hstr);
        window.Content(textblock);
        window.Activate();
    }
    catch(::winrt::hresult_error const &e)
    {
      ::fast_io::io::perrln(e.message());
    }
  private:
    winrt::Microsoft::UI::Xaml::Window window{ nullptr };
    winrt::Microsoft::UI::Xaml::Controls::TextBlock textblock{ };
};

int main()
{
    winrt::init_apartment(winrt::apartment_type::single_threaded);

    mddbootstapper mdd;
    ::winrt::Microsoft::UI::Xaml::Application::Start([](auto &&) { winrt::make<App>(); });
}

/*
You need:
https://github.com/trcrsired/windows-msvc-sysroot
and clang of course
https://github.com/trcrsired/llvm-releases/releases

clang++ -c pch.hpp -O3 -std=c++26 -flto=thin --config=d:\cfgs\x86_64-windows-msvc.cfg -fuse-ld=lld
clang++ -o main.exe main.cpp -include-pch pch.hpp.pch -O3 -std=c++26 -flto=thin -fuse-ld=lld --config=d:\cfgs\x86_64-windows-msvc.cfg -lole32 -loleaut32 -lruntimeobject -lmicrosoft.windowsappruntime.bootstrap

my cfg:
--target=x86_64-windows-msvc --sysroot=D:/toolchains/windows-msvc-sysroot -fuse-ld=lld -std=c++26 -ID:/libraries/fast_io/include -D_DLL=1 -lmsvcrt
*/