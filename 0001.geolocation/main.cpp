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
} catch (::std::exception const &e) {
  ::fast_io::perrln(fast_io::mnp::os_c_str(e.what()));
  return 1;
} catch (...) {
  ::fast_io::perr("Unknown exception\n");
  return 1;
}
