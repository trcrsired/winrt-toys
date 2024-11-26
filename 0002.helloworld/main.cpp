class App : public winrt::Microsoft::UI::Xaml::ApplicationT<App>
{
  public:
    void OnLaunched(winrt::Microsoft::UI::Xaml::LaunchActivatedEventArgs const &)
    {
        window = winrt::Microsoft::UI::Xaml::Window();
        window.Title(L"Win UI3 Main Window");
        window.Activate();
    }

  private:
    winrt::Microsoft::UI::Xaml::Window window{nullptr};
};

int main()
{
    winrt::init_apartment(winrt::apartment_type::single_threaded);

    mddbootstapper mdd;
    ::winrt::Microsoft::UI::Xaml::Application::Start([](auto &&) { winrt::make<App>(); });
}

/*
clang++ -c pch.hpp -O3 -std=c++26 -flto=thin --config=d:\cfgs\x86_64-windows-msvc.cfg -fuse-ld=lld
clang++ -o main.exe main.cpp -include-pch pch.hpp.pch -O3 -std=c++26 -flto=thin -fuse-ld=lld --config=d:\cfgs\x86_64-windows-msvc.cfg -lole32 -loleaut32 -lruntimeobject -lmicrosoft.windowsappruntime.bootstrap

my cfg:
--target=x86_64-windows-msvc --sysroot=D:/toolchains/windows-msvc-sysroot -fuse-ld=lld -std=c++26 -ID:/libraries/fast_io/include -D_DLL=1 -lmsvcrt
*/