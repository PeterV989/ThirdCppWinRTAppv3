#pragma once
#include "CalcButton.g.h"

namespace winrt::ThirdCppWinRTAppv3::implementation
{
    struct CalcButton : CalcButtonT<CalcButton>
    {
        CalcButton() = default;
        winrt::event_token PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const&);
        void PropertyChanged(winrt::event_token const&);

        static winrt::Microsoft::UI::Xaml::DependencyProperty ButtonBackgroundProperty();
        static winrt::Microsoft::UI::Xaml::DependencyProperty TopTextProperty();
        static winrt::Microsoft::UI::Xaml::DependencyProperty TopForegroundProperty();
        static winrt::Microsoft::UI::Xaml::DependencyProperty BottomTextProperty();
        static winrt::Microsoft::UI::Xaml::DependencyProperty BottomForegroundProperty();

        winrt::Microsoft::UI::Xaml::Media::Brush ButtonBackground();
        void ButtonBackground(winrt::Microsoft::UI::Xaml::Media::Brush const&);

        hstring TopText();
        void TopText(hstring const&);
        winrt::Microsoft::UI::Xaml::Media::Brush TopForeground();
        void TopForeground(winrt::Microsoft::UI::Xaml::Media::Brush const&);

        hstring BottomText();
        void BottomText(hstring const&);
        winrt::Microsoft::UI::Xaml::Media::Brush BottomForeground();
        void BottomForeground(winrt::Microsoft::UI::Xaml::Media::Brush const&);

        static void OnButtonBackgroundChanged(winrt::Microsoft::UI::Xaml::DependencyObject const&, winrt::Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const&);
        static void OnTopTextChanged(winrt::Microsoft::UI::Xaml::DependencyObject const&, winrt::Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const&);
        static void OnTopForegroundChanged(winrt::Microsoft::UI::Xaml::DependencyObject const&, winrt::Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const&);
        static void OnBottomTextChanged(winrt::Microsoft::UI::Xaml::DependencyObject const&, winrt::Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const&);
        static void OnBottomForegroundChanged(winrt::Microsoft::UI::Xaml::DependencyObject const&, winrt::Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const&);

        void myButton_Click(IInspectable const&, winrt::Microsoft::UI::Xaml::RoutedEventArgs const&);

    private:
        static winrt::Microsoft::UI::Xaml::DependencyProperty m_buttonBackgroundProperty;
        static winrt::Microsoft::UI::Xaml::DependencyProperty m_topTextProperty;
        static winrt::Microsoft::UI::Xaml::DependencyProperty m_topForegroundProperty;
        static winrt::Microsoft::UI::Xaml::DependencyProperty m_bottomTextProperty;
        static winrt::Microsoft::UI::Xaml::DependencyProperty m_bottomForegroundProperty;

    protected:
        winrt::event<winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;

    };
}
namespace winrt::ThirdCppWinRTAppv3::factory_implementation
{
    struct CalcButton : CalcButtonT<CalcButton, implementation::CalcButton>
    {
    };
}
