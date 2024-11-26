
using namespace winrt;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Markup;
using namespace Windows::UI::Xaml::Navigation;

struct App : winrt::Windows::UI::Xaml::ApplicationT<App>
{
    App() {
//        this->InitializeComponent();
    }
    
    void OnLaunched(winrt::Windows::ApplicationModel::Activation::LaunchActivatedEventArgs const&)
    {
//        winrt::Window window = winrt::Window::Current();
//        auto mainPage = winrt::make<winrt::Windows::UI::Xaml::MainPage>();
//        window.Content(mainPage);
//        window.Activate();
    }
};

int main() try{
//  ::fast_io::native_file_loader mainpagexml("mainpage.xml");


  ::winrt::init_apartment();

    winrt::Windows::UI::Xaml::Application::Start([&](auto &&)
    {});
#if 0
  using namespace winrt;
  using namespace Windows::Foundation;
  using namespace Windows::Devices::Geolocation;
  using namespace ::fast_io::io;
    // 创建主窗口
    Windows::UI::Xaml::Window window = Windows::UI::Xaml::Window::Current();
        TextBlock textBlock;
    textBlock.Text(L"Hello, World!");
    textBlock.HorizontalAlignment(HorizontalAlignment::Center);
    textBlock.VerticalAlignment(VerticalAlignment::Center);

    TextBlock textBlock;
    textBlock.Text(L"Hello, World!");
    textBlock.HorizontalAlignment(HorizontalAlignment::Center);
    textBlock.VerticalAlignment(VerticalAlignment::Center);

    
    // 将 TextBlock 设置为窗口内容
    window.Content(textBlock);

        // 激活窗口
        window.Activate();

    winrt::Windows::UI::Xaml::Application::Start([&](auto &&)
    {
            auto window = Windows::UI::Xaml::Window::Current();
    //        auto dispatcher = window.Dispatcher();
    //       dispatcher.ProcessEvents(CoreProcessEventsOption::ProcessUntilQuit);
    });
#endif
}
catch(winrt::hresult_error const & e)
{
    ::fast_io::io::perrln(e.message());
    return 1;
}
catch(...)
{
    ::fast_io::io::perrln("EH\n");
    return 1;
}