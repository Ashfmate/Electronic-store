#pragma once

typedef const char* string;

class Login_page
{
public:
	enum class Choices
	{
		Start = -1,
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
	static constexpr string expressions[size_t(Choices::Count)] = 
	{"Log in" , "Register" , "Quit"};
	static constexpr int up_key = 72;
	static constexpr int down_key = 80;
};

