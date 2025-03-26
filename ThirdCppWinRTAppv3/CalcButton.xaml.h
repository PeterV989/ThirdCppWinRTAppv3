#pragma once
#include "CalcButton.g.h"

namespace winrt::ThirdCppWinRTAppv3::implementation
{
    struct CalcButton : CalcButtonT<CalcButton>
    {
        CalcButton();
        void CalcButton::RaisePropertyChanged(winrt::hstring const& property);
        winrt::event_token PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const&);
        void PropertyChanged(winrt::event_token const&);
        //static void OnPropertyChanged(winrt::Microsoft::UI::Xaml::DependencyObject const&, winrt::Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const&);

        static Microsoft::UI::Xaml::DependencyProperty ButtonBackgroundProperty();
        winrt::Microsoft::UI::Xaml::Media::Brush ButtonBackground();
        void ButtonBackground(winrt::Microsoft::UI::Xaml::Media::Brush const&);
        static void OnButtonBackgroundChanged(winrt::Microsoft::UI::Xaml::DependencyObject const&, winrt::Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const&);

        static Microsoft::UI::Xaml::DependencyProperty TopTextProperty();
        hstring TopText();
        void TopText(hstring const&);
        static void OnTopTextChanged(winrt::Microsoft::UI::Xaml::DependencyObject const&, winrt::Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const&);

        static Microsoft::UI::Xaml::DependencyProperty TopForegroundProperty();
        winrt::Microsoft::UI::Xaml::Media::Brush TopForeground();
        void TopForeground(winrt::Microsoft::UI::Xaml::Media::Brush const&);
        static void OnTopForegroundChanged(winrt::Microsoft::UI::Xaml::DependencyObject const&, winrt::Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const&);

        static Microsoft::UI::Xaml::DependencyProperty BottomTextProperty();
        hstring BottomText();
        void BottomText(hstring const&);
        static void OnBottomTextChanged(winrt::Microsoft::UI::Xaml::DependencyObject const&, winrt::Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const&);

        static Microsoft::UI::Xaml::DependencyProperty BottomForegroundProperty();
        winrt::Microsoft::UI::Xaml::Media::Brush BottomForeground();
        void BottomForeground(winrt::Microsoft::UI::Xaml::Media::Brush const&);
        static void OnBottomForegroundChanged(winrt::Microsoft::UI::Xaml::DependencyObject const&, winrt::Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const&);

        static Microsoft::UI::Xaml::DependencyProperty TopFontWeightProperty();
        winrt::Windows::UI::Text::FontWeight TopFontWeight();
        void TopFontWeight(winrt::Windows::UI::Text::FontWeight const&);
        static void OnTopFontWeightChanged(winrt::Microsoft::UI::Xaml::DependencyObject const&, winrt::Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const&);

        static Microsoft::UI::Xaml::DependencyProperty BottomFontWeightProperty();
        winrt::Windows::UI::Text::FontWeight BottomFontWeight();
        void BottomFontWeight(winrt::Windows::UI::Text::FontWeight const&);
        static void OnBottomFontWeightChanged(winrt::Microsoft::UI::Xaml::DependencyObject const&, winrt::Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const&);

        static Microsoft::UI::Xaml::DependencyProperty PointerOverColorProperty();
        winrt::Microsoft::UI::Xaml::Media::Brush PointerOverColor();
        void PointerOverColor(winrt::Microsoft::UI::Xaml::Media::Brush const&);
        static void OnPointerOverColorChanged(winrt::Microsoft::UI::Xaml::DependencyObject const&, winrt::Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const&);

        static Microsoft::UI::Xaml::DependencyProperty PressedColorProperty();
        winrt::Microsoft::UI::Xaml::Media::Brush PressedColor();
        void PressedColor(winrt::Microsoft::UI::Xaml::Media::Brush const&);
        static void OnPressedColorChanged(winrt::Microsoft::UI::Xaml::DependencyObject const&, winrt::Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const&);

        static Microsoft::UI::Xaml::DependencyProperty DisabledColorProperty();
        winrt::Microsoft::UI::Xaml::Media::Brush DisabledColor();
        void DisabledColor(winrt::Microsoft::UI::Xaml::Media::Brush const&);
        static void OnDisabledColorChanged(winrt::Microsoft::UI::Xaml::DependencyObject const&, winrt::Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const&);

        winrt::event_token MyCalcButtonClicked(winrt::Windows::Foundation::TypedEventHandler<ThirdCppWinRTAppv3::CalcButton, winrt::Microsoft::UI::Xaml::RoutedEventArgs> const&);
        void MyCalcButtonClicked(winrt::event_token const& token) noexcept;
        winrt::event<winrt::Windows::Foundation::TypedEventHandler<ThirdCppWinRTAppv3::CalcButton, winrt::Microsoft::UI::Xaml::RoutedEventArgs>> m_clickToken;
        void MyCalcButton_Click([[maybe_unused]] IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& args);

        winrt::hstring m_topText;
        winrt::hstring m_bottomText;
        winrt::Windows::UI::Text::FontWeight m_topFontWeight{ 0 };
        winrt::Windows::UI::Text::FontWeight m_bottomFontWeight{ 0 };
        winrt::Microsoft::UI::Xaml::Media::Brush  m_bottomForeground{ nullptr };
        winrt::Microsoft::UI::Xaml::Media::Brush m_topForeground{ nullptr };
        winrt::Microsoft::UI::Xaml::Media::Brush m_buttonBackground{ nullptr };
        winrt::Microsoft::UI::Xaml::Media::Brush m_pointerOverColor{ nullptr };
        winrt::Microsoft::UI::Xaml::Media::Brush m_pressedColor{ nullptr };
        winrt::Microsoft::UI::Xaml::Media::Brush m_disabledColor{ nullptr };

    private:
        static winrt::Microsoft::UI::Xaml::DependencyProperty m_topTextProperty;
        static winrt::Microsoft::UI::Xaml::DependencyProperty m_bottomTextProperty;
        static winrt::Microsoft::UI::Xaml::DependencyProperty m_topFontWeightProperty;
        static winrt::Microsoft::UI::Xaml::DependencyProperty m_bottomFontWeightProperty;
        static winrt::Microsoft::UI::Xaml::DependencyProperty m_bottomForegroundProperty;
        static winrt::Microsoft::UI::Xaml::DependencyProperty m_topForegroundProperty;
        static winrt::Microsoft::UI::Xaml::DependencyProperty m_buttonBackgroundProperty;
        static winrt::Microsoft::UI::Xaml::DependencyProperty m_pointerOverColorProperty;
        static winrt::Microsoft::UI::Xaml::DependencyProperty m_pressedColorProperty;
        static winrt::Microsoft::UI::Xaml::DependencyProperty m_disabledColorProperty;

        static winrt::Microsoft::UI::Xaml::Media::Brush m_buttonBackgroundBrush;
 
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
