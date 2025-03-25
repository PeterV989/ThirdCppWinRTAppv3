#pragma once

#include "MainWindow.g.h"

namespace winrt::ThirdCppWinRTAppv3::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow();
        void OnCalcButtonClicked(ThirdCppWinRTAppv3::CalcButton const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const&);
    protected:
        void OnMainWindowLoaded(winrt::Windows::Foundation::IInspectable const&, winrt::Microsoft::UI::Xaml::RoutedEventArgs const&);
    private:
        bool m_isFKeyPressed{ false };
    };
}

namespace winrt::ThirdCppWinRTAppv3::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}