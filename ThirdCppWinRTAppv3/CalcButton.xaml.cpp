#include "pch.h"
#include "CalcButton.xaml.h"
#include "CalcButton.g.cpp"
#include <typeinfo>

namespace winrt::ThirdCppWinRTAppv3::implementation
{
	CalcButton::CalcButton()
	{
		m_buttonBackground = nullptr;
		m_topText = L"";
		m_topForeground = nullptr;
		m_bottomText = L"";
		m_topFontWeight = winrt::Windows::UI::Text::FontWeights::Black();
		m_bottomFontWeight = winrt::Windows::UI::Text::FontWeights::Black();
		m_bottomForeground = nullptr;

		DefaultStyleKey(winrt::box_value(L"ThirdCppWinRTAppv3.CalcButton"));
		
		//this->FindName(L"CalcButton").as<winrt::Microsoft::UI::Xaml::Controls::Button>().Click({ this, &CalcButton::MyCalcButton_Click });
	}

	void CalcButton::RaisePropertyChanged(winrt::hstring const& property)
	{
		m_propertyChanged(*this, winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ property });
	}

	winrt::event_token CalcButton::PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& h)
	{
		return m_propertyChanged.add(h);
	}

	void CalcButton::PropertyChanged(winrt::event_token const& t)
	{
		m_propertyChanged.remove(t);
	}

	void CalcButton::MyCalcButton_Click([[maybe_unused]] winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& args)
	{
		const char* typeName = typeid(sender).name();
		int size_needed = MultiByteToWideChar(CP_UTF8, 0, typeName, -1, NULL, 0);
		std::wstring wstrTo(size_needed, 0);
		MultiByteToWideChar(CP_UTF8, 0, typeName, -1, &wstrTo[0], size_needed);
		OutputDebugStringW(wstrTo.c_str()); OutputDebugStringW(L"\nClass Name: ");
		winrt::hstring className = winrt::get_class_name(sender);
		OutputDebugStringW(className.c_str()); OutputDebugStringW(L"\n");
		m_clickToken(*this, args);
	}

	winrt::event_token CalcButton::MyCalcButtonClicked(winrt::Windows::Foundation::TypedEventHandler<ThirdCppWinRTAppv3::CalcButton, winrt::Microsoft::UI::Xaml::RoutedEventArgs> const& handler)
	{
		return m_clickToken.add(handler);
	}

	void CalcButton::MyCalcButtonClicked(winrt::event_token const& token) noexcept
	{
		m_clickToken.remove(token);
	}

	winrt::Microsoft::UI::Xaml::Media::Brush CalcButton::m_buttonBackgroundBrush = nullptr;

	winrt::Microsoft::UI::Xaml::DependencyProperty CalcButton::m_topTextProperty =
		winrt::Microsoft::UI::Xaml::DependencyProperty::Register(
			L"TopText",
			winrt::xaml_typename<hstring>(),
			winrt::xaml_typename<winrt::ThirdCppWinRTAppv3::CalcButton>(),
			winrt::Microsoft::UI::Xaml::PropertyMetadata{ winrt::box_value(L""), winrt::Microsoft::UI::Xaml::PropertyChangedCallback{ &CalcButton::OnTopTextChanged } }
		);

	winrt::Microsoft::UI::Xaml::DependencyProperty CalcButton::m_bottomTextProperty =
		winrt::Microsoft::UI::Xaml::DependencyProperty::Register(
			L"BottomText",
			winrt::xaml_typename<hstring>(),
			winrt::xaml_typename<winrt::ThirdCppWinRTAppv3::CalcButton>(),
			winrt::Microsoft::UI::Xaml::PropertyMetadata{ winrt::box_value(L""), winrt::Microsoft::UI::Xaml::PropertyChangedCallback{&CalcButton::OnBottomTextChanged}}
		);

	winrt::Microsoft::UI::Xaml::DependencyProperty CalcButton::m_topFontWeightProperty =
		winrt::Microsoft::UI::Xaml::DependencyProperty::Register(
			L"TopFontWeight",
			winrt::xaml_typename<winrt::Windows::UI::Text::FontWeight>(),
			winrt::xaml_typename<winrt::ThirdCppWinRTAppv3::CalcButton>(),
			winrt::Microsoft::UI::Xaml::PropertyMetadata{ nullptr, winrt::Microsoft::UI::Xaml::PropertyChangedCallback{ &CalcButton::OnTopFontWeightChanged } }
		);

	winrt::Microsoft::UI::Xaml::DependencyProperty CalcButton::m_bottomFontWeightProperty =
		winrt::Microsoft::UI::Xaml::DependencyProperty::Register(
			L"BottomFontWeight",
			winrt::xaml_typename<winrt::Windows::UI::Text::FontWeight>(),
			winrt::xaml_typename<winrt::ThirdCppWinRTAppv3::CalcButton>(),
			winrt::Microsoft::UI::Xaml::PropertyMetadata{ nullptr, winrt::Microsoft::UI::Xaml::PropertyChangedCallback{ &CalcButton::OnBottomFontWeightChanged } }
		);

	winrt::Microsoft::UI::Xaml::DependencyProperty CalcButton::m_buttonBackgroundProperty =
		winrt::Microsoft::UI::Xaml::DependencyProperty::Register(
			L"ButtonBackground",
			winrt::xaml_typename<winrt::Microsoft::UI::Xaml::Media::Brush>(),
			winrt::xaml_typename<winrt::ThirdCppWinRTAppv3::CalcButton>(),
			winrt::Microsoft::UI::Xaml::PropertyMetadata{ nullptr, winrt::Microsoft::UI::Xaml::PropertyChangedCallback{&CalcButton::OnButtonBackgroundChanged} }
		);

	winrt::Microsoft::UI::Xaml::DependencyProperty CalcButton::m_topForegroundProperty =
		winrt::Microsoft::UI::Xaml::DependencyProperty::Register(
			L"TopForeground",
			winrt::xaml_typename<winrt::Microsoft::UI::Xaml::Media::Brush>(),
			winrt::xaml_typename<winrt::ThirdCppWinRTAppv3::CalcButton>(),
			winrt::Microsoft::UI::Xaml::PropertyMetadata{ nullptr, winrt::Microsoft::UI::Xaml::PropertyChangedCallback{ &CalcButton::OnTopForegroundChanged } }
		);

	winrt::Microsoft::UI::Xaml::DependencyProperty CalcButton::m_bottomForegroundProperty =
		winrt::Microsoft::UI::Xaml::DependencyProperty::Register(
			L"BottomForeground",
			winrt::xaml_typename<winrt::Microsoft::UI::Xaml::Media::Brush>(),
			winrt::xaml_typename<winrt::ThirdCppWinRTAppv3::CalcButton>(),
			winrt::Microsoft::UI::Xaml::PropertyMetadata{ nullptr, winrt::Microsoft::UI::Xaml::PropertyChangedCallback{ &CalcButton::OnBottomForegroundChanged } }
		);

	winrt::Microsoft::UI::Xaml::DependencyProperty CalcButton::m_pointerOverColorProperty =
		winrt::Microsoft::UI::Xaml::DependencyProperty::Register(
			L"PointerOverColor",
			winrt::xaml_typename<winrt::Microsoft::UI::Xaml::Media::Brush>(),
			winrt::xaml_typename<winrt::ThirdCppWinRTAppv3::CalcButton>(),
			winrt::Microsoft::UI::Xaml::PropertyMetadata{ nullptr, winrt::Microsoft::UI::Xaml::PropertyChangedCallback{ &CalcButton::OnPointerOverColorChanged } }
		);

	winrt::Microsoft::UI::Xaml::DependencyProperty CalcButton::m_pressedColorProperty =
		winrt::Microsoft::UI::Xaml::DependencyProperty::Register(
			L"PresssedColor",
			winrt::xaml_typename<winrt::Microsoft::UI::Xaml::Media::Brush>(),
			winrt::xaml_typename<winrt::ThirdCppWinRTAppv3::CalcButton>(),
			winrt::Microsoft::UI::Xaml::PropertyMetadata{ nullptr, winrt::Microsoft::UI::Xaml::PropertyChangedCallback{ &CalcButton::OnPressedColorChanged } }
		);

	winrt::Microsoft::UI::Xaml::DependencyProperty CalcButton::m_disabledColorProperty =
		winrt::Microsoft::UI::Xaml::DependencyProperty::Register(
			L"DisabledColor",
			winrt::xaml_typename<winrt::Microsoft::UI::Xaml::Media::Brush>(),
			winrt::xaml_typename<winrt::ThirdCppWinRTAppv3::CalcButton>(),
			winrt::Microsoft::UI::Xaml::PropertyMetadata{ nullptr, winrt::Microsoft::UI::Xaml::PropertyChangedCallback{ &CalcButton::OnDisabledColorChanged } }
		);

	winrt::Microsoft::UI::Xaml::Media::Brush CalcButton::ButtonBackground()
	{
		return GetValue(CalcButton::m_buttonBackgroundProperty).as<winrt::Microsoft::UI::Xaml::Media::Brush>();
	}

	void CalcButton::ButtonBackground(winrt::Microsoft::UI::Xaml::Media::Brush const& value)
	{
		if (value != m_buttonBackground)
		{
			SetValue(CalcButton::m_buttonBackgroundProperty, value);
			m_buttonBackground = value;
		}
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

	hstringCalcButton::TopText()
	{
		return winrt::unbox_value<hstring>(GetValue(m_topTextProperty));
	}

	void CalcButton::TopText(hstring const& value)
	{
		if (value != m_topText)
		{
			SetValue(m_topTextProperty, winrt::box_value(value));
			m_topText = value;
		}
	}

	void CalcButton::OnTopTextChanged(winrt::Microsoft::UI::Xaml::DependencyObject const& d, winrt::Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const& e)
	{
	    if (auto control = d.try_as<winrt::ThirdCppWinRTAppv3::CalcButton>())
	    {
	        control.TopText(e.NewValue().as<hstring>());
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
		if (value != m_topForeground)
		{
			SetValue(m_topForegroundProperty, value);
			m_topForeground = value;
		}
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

	winrt::Windows::UI::Text::FontWeight CalcButton::TopFontWeight()
	{
		return winrt::unbox_value<winrt::Windows::UI::Text::FontWeight>(GetValue(m_topFontWeightProperty));
	}

	void CalcButton::TopFontWeight(winrt::Windows::UI::Text::FontWeight const& value)
	{
		if (value != m_topFontWeight)
		{
			SetValue(m_topFontWeightProperty, winrt::box_value(value));
			m_topFontWeight = value;
		}
	}

	void CalcButton::OnTopFontWeightChanged(winrt::Microsoft::UI::Xaml::DependencyObject const& d, winrt::Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const& e)
	{
		if (auto control = d.try_as<winrt::ThirdCppWinRTAppv3::CalcButton>())
		{
			if (auto value = e.NewValue().try_as<winrt::Windows::UI::Text::FontWeight>())
			{
				if (value != control.GetValue(CalcButton::TopFontWeightProperty()).as<winrt::Windows::UI::Text::FontWeight>())
				{
					auto t = L"TopFontWeight name: " + control.Name();
					OutputDebugStringW(t.c_str());
					control.TopFontWeight(e.NewValue().as<winrt::Windows::UI::Text::FontWeight>());
				}
			}
		}
	}

	winrt::Microsoft::UI::Xaml::DependencyProperty CalcButton::TopFontWeightProperty()
	{
		return m_topFontWeightProperty;
	}

	hstring CalcButton::BottomText()
	{
		return winrt::unbox_value<hstring>(GetValue(BottomTextProperty()));
	}

	void CalcButton::BottomText(hstring const& value)
	{
		if (value != m_bottomText)
		{
			SetValue(BottomTextProperty(), winrt::box_value(value));
			m_bottomText = value;
		}
	}

	void CalcButton::OnBottomTextChanged(winrt::Microsoft::UI::Xaml::DependencyObject const& d, winrt::Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const& e)
	{
		if (auto control = d.try_as<winrt::ThirdCppWinRTAppv3::CalcButton>())
		{
			control.BottomText(e.NewValue().as<hstring>());
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
		if (value != m_bottomForeground)
		{
			SetValue(m_bottomForegroundProperty, value);
			m_bottomForeground = value;
		}
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

	winrt::Windows::UI::Text::FontWeight CalcButton::BottomFontWeight()
	{
		return winrt::unbox_value<winrt::Windows::UI::Text::FontWeight>(GetValue(m_bottomFontWeightProperty));
	}

	void CalcButton::BottomFontWeight(winrt::Windows::UI::Text::FontWeight const& value)
	{
		if (value != m_bottomFontWeight)
		{
			SetValue(m_bottomFontWeightProperty, box_value(value));
			m_bottomFontWeight = value;
		}
	}

	void CalcButton::OnBottomFontWeightChanged(winrt::Microsoft::UI::Xaml::DependencyObject const& d, winrt::Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const& e)
	{
		if (auto control = d.try_as<winrt::ThirdCppWinRTAppv3::CalcButton>())
		{
			if (auto value = e.NewValue().try_as<winrt::Windows::UI::Text::FontWeight>())
			{
				if (value != control.GetValue(CalcButton::BottomFontWeightProperty()).as<winrt::Windows::UI::Text::FontWeight>())
				{
					auto t = L"BottomFontWeight name: " + control.Name();
					OutputDebugStringW(t.c_str());
					control.BottomFontWeight(e.NewValue().as<winrt::Windows::UI::Text::FontWeight>());
				}
			}
		}
	}

	winrt::Microsoft::UI::Xaml::DependencyProperty CalcButton::BottomFontWeightProperty()
	{
		return m_bottomFontWeightProperty;
	}

	winrt::Microsoft::UI::Xaml::Media::Brush CalcButton::PointerOverColor()
	{
		return GetValue(m_pointerOverColorProperty).as<winrt::Microsoft::UI::Xaml::Media::Brush>();
	}

	void CalcButton::PointerOverColor(winrt::Microsoft::UI::Xaml::Media::Brush const& value)
	{
		if (value != m_pointerOverColor)
		{
			SetValue(m_pointerOverColorProperty, value);
			m_pointerOverColor = value;
		}
	}

	void CalcButton::OnPointerOverColorChanged(winrt::Microsoft::UI::Xaml::DependencyObject const& d, winrt::Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const& e)
	{
		if (auto control = d.try_as<winrt::ThirdCppWinRTAppv3::CalcButton>())
		{
			control.PointerOverColor(e.NewValue().as<winrt::Microsoft::UI::Xaml::Media::Brush>());
		}
	}

	winrt::Microsoft::UI::Xaml::DependencyProperty CalcButton::PointerOverColorProperty()
	{
		return m_pointerOverColorProperty;
	}

	winrt::Microsoft::UI::Xaml::Media::Brush CalcButton::PressedColor()
	{
		return GetValue(m_pressedColorProperty).as<winrt::Microsoft::UI::Xaml::Media::Brush>();
	}

	void CalcButton::PressedColor(winrt::Microsoft::UI::Xaml::Media::Brush const& value)
	{
		if (value != m_pressedColor)
		{
			SetValue(m_pressedColorProperty, value);
			m_pressedColor = value;
		}
	}

	void CalcButton::OnPressedColorChanged(winrt::Microsoft::UI::Xaml::DependencyObject const& d, winrt::Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const& e)
	{
		if (auto control = d.try_as<winrt::ThirdCppWinRTAppv3::CalcButton>())
		{
			control.PressedColor(e.NewValue().as<winrt::Microsoft::UI::Xaml::Media::Brush>());
		}
	}

	winrt::Microsoft::UI::Xaml::DependencyProperty CalcButton::PressedColorProperty()
	{
		return m_pressedColorProperty;
	}

	winrt::Microsoft::UI::Xaml::Media::Brush CalcButton::DisabledColor()
	{
		return GetValue(m_disabledColorProperty).as<winrt::Microsoft::UI::Xaml::Media::Brush>();
	}

	void CalcButton::DisabledColor(winrt::Microsoft::UI::Xaml::Media::Brush const& value)
	{
		if (value != m_disabledColor)
		{
			SetValue(m_disabledColorProperty, value);
			m_disabledColor = value;
		}
	}

	void CalcButton::OnDisabledColorChanged(winrt::Microsoft::UI::Xaml::DependencyObject const& d, winrt::Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const& e)
	{
		if (auto control = d.try_as<winrt::ThirdCppWinRTAppv3::CalcButton>())
		{
			control.DisabledColor(e.NewValue().as<winrt::Microsoft::UI::Xaml::Media::Brush>());
		}
	}

	winrt::Microsoft::UI::Xaml::DependencyProperty CalcButton::DisabledColorProperty()
	{
		return m_disabledColorProperty;
	}
}