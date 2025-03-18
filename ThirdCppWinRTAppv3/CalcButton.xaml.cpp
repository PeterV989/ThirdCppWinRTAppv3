#include "pch.h"
#include "CalcButton.xaml.h"
#include "CalcButton.g.cpp"
#include <typeinfo>

namespace winrt::ThirdCppWinRTAppv3::implementation
{
    winrt::event_token CalcButton::PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& h)
    {
        return m_propertyChanged.add(h);
    }
    void CalcButton::PropertyChanged(winrt::event_token const& t)
    {
        m_propertyChanged.remove(t);
    }

    void CalcButton::myButton_Click(IInspectable const&, winrt::Microsoft::UI::Xaml::RoutedEventArgs const&)
    {
        winrt::Microsoft::UI::Xaml::Media::SolidColorBrush red{ winrt::Microsoft::UI::Colors::Red() };
        myButton().Background(red);
        if (auto tb = this->FindName(L"Top").try_as<winrt::Microsoft::UI::Xaml::Controls::TextBlock>())
        {
            tb.Text(L"Top 1");
        }

        if (auto bb = this->FindName(L"Bottom").try_as<winrt::Microsoft::UI::Xaml::Controls::TextBlock>())
        {
            bb.Text(L"Bottom 1");
        }
    }

    winrt::Microsoft::UI::Xaml::DependencyProperty CalcButton::m_buttonBackgroundProperty =
        winrt::Microsoft::UI::Xaml::DependencyProperty::Register(
            L"ButtonBackground",
            winrt::xaml_typename<winrt::Microsoft::UI::Xaml::Media::Brush>(),
            winrt::xaml_typename<winrt::ThirdCppWinRTAppv3::CalcButton>(),
            winrt::Microsoft::UI::Xaml::PropertyMetadata{ nullptr, winrt::Microsoft::UI::Xaml::PropertyChangedCallback{ &CalcButton::OnButtonBackgroundChanged } }
        );

    winrt::Microsoft::UI::Xaml::DependencyProperty CalcButton::m_topTextProperty =
        winrt::Microsoft::UI::Xaml::DependencyProperty::Register(
            L"TopText",
            winrt::xaml_typename<hstring>(),
            winrt::xaml_typename<winrt::ThirdCppWinRTAppv3::CalcButton>(),
            winrt::Microsoft::UI::Xaml::PropertyMetadata{ winrt::box_value(L"top"), winrt::Microsoft::UI::Xaml::PropertyChangedCallback{ &CalcButton::OnTopTextChanged } }
        );

    winrt::Microsoft::UI::Xaml::DependencyProperty CalcButton::m_topForegroundProperty =
        winrt::Microsoft::UI::Xaml::DependencyProperty::Register(
            L"TopForeground",
            winrt::xaml_typename<winrt::Microsoft::UI::Xaml::Media::Brush>(),
            winrt::xaml_typename<winrt::ThirdCppWinRTAppv3::CalcButton>(),
            winrt::Microsoft::UI::Xaml::PropertyMetadata{ nullptr, winrt::Microsoft::UI::Xaml::PropertyChangedCallback{ &CalcButton::OnTopForegroundChanged } }
        );

    winrt::Microsoft::UI::Xaml::DependencyProperty CalcButton::m_bottomTextProperty =
        winrt::Microsoft::UI::Xaml::DependencyProperty::Register(
            L"BottomText",
            winrt::xaml_typename<hstring>(),
            winrt::xaml_typename<winrt::ThirdCppWinRTAppv3::CalcButton>(),
            winrt::Microsoft::UI::Xaml::PropertyMetadata{ winrt::box_value(L"bottom"), winrt::Microsoft::UI::Xaml::PropertyChangedCallback{ &CalcButton::OnBottomTextChanged } }
        );

    winrt::Microsoft::UI::Xaml::DependencyProperty CalcButton::m_bottomForegroundProperty =
        winrt::Microsoft::UI::Xaml::DependencyProperty::Register(
            L"BottomForeground",
            winrt::xaml_typename<winrt::Microsoft::UI::Xaml::Media::Brush>(),
            winrt::xaml_typename<winrt::ThirdCppWinRTAppv3::CalcButton>(),
            winrt::Microsoft::UI::Xaml::PropertyMetadata{ nullptr, winrt::Microsoft::UI::Xaml::PropertyChangedCallback{ &CalcButton::OnBottomForegroundChanged } }
        );

    winrt::Microsoft::UI::Xaml::Media::Brush CalcButton::ButtonBackground()
    {
        return winrt::unbox_value< winrt::Microsoft::UI::Xaml::Media::Brush>(GetValue(m_buttonBackgroundProperty));
    }

    void CalcButton::ButtonBackground(winrt::Microsoft::UI::Xaml::Media::Brush const& value)
    {
        SetValue(m_buttonBackgroundProperty, value);
    }

    void CalcButton::OnButtonBackgroundChanged(winrt::Microsoft::UI::Xaml::DependencyObject const& d, winrt::Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const& e)
    {
        if (auto control = d.try_as<winrt::ThirdCppWinRTAppv3::CalcButton>())
        {
            control.ButtonBackground(e.NewValue().as<winrt::Microsoft::UI::Xaml::Media::Brush>());
        }
    }

    winrt::Microsoft::UI::Xaml::DependencyProperty CalcButton::ButtonBackgroundProperty()
    {
        return m_buttonBackgroundProperty;
    }

    hstring CalcButton::TopText()
    {
        return winrt::unbox_value<hstring>(GetValue(m_topTextProperty));
    }

    void CalcButton::TopText(hstring const& value)
    {
        SetValue(m_topTextProperty, winrt::box_value(value));
    }

    void CalcButton::OnTopTextChanged(winrt::Microsoft::UI::Xaml::DependencyObject const& d, winrt::Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const& e)
    {
        if (auto control = d.try_as<winrt::ThirdCppWinRTAppv3::CalcButton>())
        {
            control.TopText(winrt::unbox_value<hstring>(e.NewValue()));
        }
    }

    winrt::Microsoft::UI::Xaml::DependencyProperty CalcButton::TopTextProperty()
    {
        return m_topTextProperty;
    }

    winrt::Microsoft::UI::Xaml::Media::Brush CalcButton::TopForeground()
    {
        return GetValue(m_topForegroundProperty).as< winrt::Microsoft::UI::Xaml::Media::Brush>();
    }

    void CalcButton::TopForeground(winrt::Microsoft::UI::Xaml::Media::Brush const& value)
    {
        SetValue(m_topForegroundProperty, value);
    }

    void CalcButton::OnTopForegroundChanged(winrt::Microsoft::UI::Xaml::DependencyObject const& d, winrt::Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const& e)
    {
        if (auto control = d.try_as<winrt::ThirdCppWinRTAppv3::CalcButton>())
        {
            control.TopForeground(e.NewValue().as<winrt::Microsoft::UI::Xaml::Media::Brush>());
        }
    }

    winrt::Microsoft::UI::Xaml::DependencyProperty CalcButton::TopForegroundProperty()
    {
        return m_topForegroundProperty;
    }

    hstring CalcButton::BottomText()
    {
        return winrt::unbox_value<hstring>(GetValue(BottomTextProperty()));
    }

    void CalcButton::BottomText(hstring const& value)
    {
        SetValue(BottomTextProperty(), winrt::box_value(value));
    }

    void CalcButton::OnBottomTextChanged(winrt::Microsoft::UI::Xaml::DependencyObject const& d, winrt::Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const& e)
    {
        if (auto control = d.try_as<winrt::ThirdCppWinRTAppv3::CalcButton>())
        {
            control.BottomText(winrt::unbox_value<hstring>(e.NewValue()));
        }
    }

    winrt::Microsoft::UI::Xaml::DependencyProperty CalcButton::BottomTextProperty()
    {
        return m_bottomTextProperty;
    }
    winrt::Microsoft::UI::Xaml::Media::Brush CalcButton::BottomForeground()
    {
        return GetValue(m_bottomForegroundProperty).as<winrt::Microsoft::UI::Xaml::Media::Brush>();
    }

    void CalcButton::BottomForeground(winrt::Microsoft::UI::Xaml::Media::Brush const& value)
    {
        SetValue(m_bottomForegroundProperty, value);
    }

    void CalcButton::OnBottomForegroundChanged(winrt::Microsoft::UI::Xaml::DependencyObject const& d, winrt::Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const& e)
    {
        if (auto control = d.try_as<winrt::ThirdCppWinRTAppv3::CalcButton>())
        {
            control.BottomForeground(e.NewValue().as<winrt::Microsoft::UI::Xaml::Media::Brush>());
        }
    }

    winrt::Microsoft::UI::Xaml::DependencyProperty CalcButton::BottomForegroundProperty()
    {
        return m_bottomForegroundProperty;
    }

}
