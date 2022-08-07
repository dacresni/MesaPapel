add_executable(Ori main.cpp connectionWrapper.cpp resources.qrc)
target_link_libraries(Ori Qt5::Quick Qt5::Qml Qt5::Gui Qt5::QuickControls2 Qt5::Widgets KF5::Kirigami2 KF5::I18n KF5::ConfigCore KF5::ConfigGui)
