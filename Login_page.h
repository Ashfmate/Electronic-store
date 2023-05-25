#pragma once

class Login_page
{
public:
	enum class Choices
	{
		Start,
		Login,
		Register,
		Quit,
		Count
	};
public:
	Choices operator()();
private:
	void draw();
	bool choice_control();
private:
	Choices choice = Choices::Login;
	static constexpr const char* login_expression = "Log in";
	static constexpr const char* register_expression = "Register";
	static constexpr const char* quit_expression = "Quit";
	static constexpr int up_key = 72;
	static constexpr int down_key = 80;
};

