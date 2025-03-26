#include "pch.h"
#include "CalcButton.xaml.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::ThirdCppWinRTAppv3::implementation
{
	MainWindow::MainWindow()
	{
		// Xaml objects should not call InitializeComponent during construction.
		// See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
		InitializeComponent();
		if (CalcGrid()) {
			CalcGrid().Loaded({ this, &MainWindow::OnMainWindowLoaded });
		}
	}

	void MainWindow::OnCalcButtonClicked(ThirdCppWinRTAppv3::CalcButton const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& /* args */)
	{
		ThirdCppWinRTAppv3::CalcButton clickedButton = sender.try_as<ThirdCppWinRTAppv3::CalcButton>();

		if (clickedButton) {
			hstring name = clickedButton.Name();
			std::wstringstream ss;

			OutputDebugStringW(name.c_str());
			if (name == L"f")
			{
				for (auto const& cb : CalcGrid().Children())
				{
					if (auto calcButton = cb.try_as<ThirdCppWinRTAppv3::CalcButton>())
					{
						if ((calcButton.Name() != L"f") && (calcButton.Name() != L"g") && (calcButton.Name() != L"ON"))
						{
							if (m_isFKeyPressed)
							{
								calcButton.TopFontWeight(winrt::Windows::UI::Text::FontWeights::Bold());
								calcButton.BottomFontWeight(winrt::Windows::UI::Text::FontWeights::Normal());
							}
							else
							{
								calcButton.TopFontWeight(winrt::Windows::UI::Text::FontWeights::Normal());
								calcButton.BottomFontWeight(winrt::Windows::UI::Text::FontWeights::Bold());
							};
						};
					};
				};
				m_isFKeyPressed = !m_isFKeyPressed;
			}
		}
	}
	void MainWindow::OnMainWindowLoaded([[maybe_unused]] winrt::Windows::Foundation::IInspectable const& sender,[[maybe_unused]] winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
	{
		ON().FindName(L"Bottom").as<winrt::Microsoft::UI::Xaml::Controls::TextBlock>().Visibility(Visibility::Collapsed);
		for (auto const& child : CalcGrid().Children())
		{
			if (auto const& calcButton = child.try_as<winrt::ThirdCppWinRTAppv3::CalcButton>())
			{
				calcButton.MyCalcButtonClicked({ this, &MainWindow::OnCalcButtonClicked } );
			};
		}
	}
}
