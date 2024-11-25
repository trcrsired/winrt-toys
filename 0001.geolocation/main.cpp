int main() try {
  ::winrt::init_apartment();
  using namespace winrt;
  using namespace Windows::Foundation;
  using namespace Windows::Devices::Geolocation;
  using namespace ::fast_io::io;

  Geolocator geolocator;
  geolocator.DesiredAccuracy(PositionAccuracy::High);
  Geoposition pos = geolocator.GetGeopositionAsync().get();

  auto const &coordinate = pos.Coordinate().Point().Position();
  println("Latitude=", coordinate.Latitude,
          "\nLongitude=", coordinate.Longitude,
          "\naltitude=", coordinate.Altitude);
} catch (::winrt::hresult_error const &e) {
  ::fast_io::perrln(e.message());
  return 1;
} catch (...) {
  ::fast_io::perr("Unknown exception\n");
  return 1;
}
/*
Need geolocation permission from windows settings for desktop applications
clang++ -o main.exe main.cpp -include-pch pch.hpp.pch -O3 -std=c++26 -flto=thin --config=d:\cfgs\x86_64-windows-msvc.cfg

D:\msys64\home\unlvs\projects\winui-toys\0001.geolocation>main.exe
Latitude=42.0721
Longitude=-75.9086
altitude=0
*/