#include <GE_Test.h>

class Sandbox : public GE_Test::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
};

GE_Test::Application* GE_Test::CreateApplication()
{
	return new Sandbox();
}