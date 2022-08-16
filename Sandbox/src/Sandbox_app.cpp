#include <GE_Test.h>

class ExLayer : public GE_Test::Layer
{
public:
	ExLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		GETEST_INFO("ExampleLayer::Update");
	}
	void OnEvent(GE_Test::Event& event) override
	{
		GETEST_TRACE("{0}", event);
	}
};

class Sandbox : public GE_Test::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExLayer());
		PushOverlay(new GE_Test::imguiLayer());
	}
	~Sandbox()
	{

	}
};

GE_Test::Application* GE_Test::CreateApplication()
{
	return new Sandbox();
}