int main() {
  using namespace winrt;
  using namespace Windows::Foundation;
  using namespace Windows::Web::Syndication;
  using namespace ::fast_io::io;
  winrt::init_apartment();

  Uri rssFeedUri{L"https://blogs.windows.com/feed"};
  SyndicationClient syndicationClient;
  syndicationClient.SetRequestHeader(L"User-Agent",
                                     L"Mozilla/5.0 (compatible; MSIE 10.0; "
                                     L"Windows NT 6.2; WOW64; Trident/6.0)");
  SyndicationFeed syndicationFeed =
      syndicationClient.RetrieveFeedAsync(rssFeedUri).get();
  for (SyndicationItem const syndicationItem : syndicationFeed.Items()) {
    winrt::hstring titleAsHstring = syndicationItem.Title().Text();

    // A workaround to remove the trademark symbol from the title string,
    // because it causes issues in this case.
    ::fast_io::wstring titleasfastiostring(
        ::fast_io::mnp::os_c_str(titleAsHstring));
    erase(titleasfastiostring, u'™');
    println(::fast_io::mnp::code_cvt(titleasfastiostring));
  }
}