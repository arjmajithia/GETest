#include "getpch.h"
#include "imguiLayer.h"

#include "imgui.h"
#include "GE_Test/Application.h"
#include "Platform/OpenGL/imguiOpenGLRenderer.h"

//Temp
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace GE_Test {

//#define BIND_EVENT_imgui(x) std::bind(&x, this, std::placeholders::_1)


	imguiLayer::imguiLayer()
		: Layer("imguiLayer")
	{
	}

	imguiLayer::~imguiLayer()
	{
	}

	void imguiLayer::OnAttach()
	{
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		//Temp, will be replaced with self made keycodes
        io.KeyMap[ImGuiKey_Tab] = GLFW_KEY_TAB;
        io.KeyMap[ImGuiKey_LeftArrow] = GLFW_KEY_LEFT;
        io.KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT;
        io.KeyMap[ImGuiKey_UpArrow] = GLFW_KEY_UP;
        io.KeyMap[ImGuiKey_DownArrow] = GLFW_KEY_DOWN;
        io.KeyMap[ImGuiKey_PageUp] = GLFW_KEY_PAGE_UP;
        io.KeyMap[ImGuiKey_PageDown] = GLFW_KEY_PAGE_DOWN;
        io.KeyMap[ImGuiKey_Home] = GLFW_KEY_HOME;
        io.KeyMap[ImGuiKey_End] = GLFW_KEY_END;
        io.KeyMap[ImGuiKey_Insert] = GLFW_KEY_INSERT;
        io.KeyMap[ImGuiKey_Delete] = GLFW_KEY_DELETE;
        io.KeyMap[ImGuiKey_Backspace] = GLFW_KEY_BACKSPACE;
        io.KeyMap[ImGuiKey_Space] = GLFW_KEY_SPACE;
        io.KeyMap[ImGuiKey_Enter] = GLFW_KEY_ENTER;
        io.KeyMap[ImGuiKey_Escape] = GLFW_KEY_ESCAPE;
        io.KeyMap[ImGuiKey_Apostrophe] = GLFW_KEY_APOSTROPHE;
        io.KeyMap[ImGuiKey_Comma] = GLFW_KEY_COMMA;
        io.KeyMap[ImGuiKey_Minus] = GLFW_KEY_MINUS;
        io.KeyMap[ImGuiKey_Period] = GLFW_KEY_PERIOD;
        io.KeyMap[ImGuiKey_Slash] = GLFW_KEY_SLASH;
        io.KeyMap[ImGuiKey_Semicolon] = GLFW_KEY_SEMICOLON;
        io.KeyMap[ImGuiKey_Equal] = GLFW_KEY_EQUAL;
        io.KeyMap[ImGuiKey_LeftBracket] = GLFW_KEY_LEFT_BRACKET;
        io.KeyMap[ImGuiKey_Backslash] = GLFW_KEY_BACKSLASH;
        io.KeyMap[ImGuiKey_RightBracket] = GLFW_KEY_RIGHT_BRACKET;
        io.KeyMap[ImGuiKey_GraveAccent] = GLFW_KEY_GRAVE_ACCENT;
        io.KeyMap[ImGuiKey_CapsLock] = GLFW_KEY_CAPS_LOCK;
        io.KeyMap[ImGuiKey_ScrollLock] = GLFW_KEY_SCROLL_LOCK;
        io.KeyMap[ImGuiKey_NumLock] = GLFW_KEY_NUM_LOCK;
        io.KeyMap[ImGuiKey_PrintScreen] = GLFW_KEY_PRINT_SCREEN;
        io.KeyMap[ImGuiKey_Pause] = GLFW_KEY_PAUSE;
        io.KeyMap[ImGuiKey_Keypad0] = GLFW_KEY_KP_0;
        io.KeyMap[ImGuiKey_Keypad1] = GLFW_KEY_KP_1;
        io.KeyMap[ImGuiKey_Keypad2] = GLFW_KEY_KP_2;
        io.KeyMap[ImGuiKey_Keypad3] = GLFW_KEY_KP_3;
        io.KeyMap[ImGuiKey_Keypad4] = GLFW_KEY_KP_4;
        io.KeyMap[ImGuiKey_Keypad5] = GLFW_KEY_KP_5;
        io.KeyMap[ImGuiKey_Keypad6] = GLFW_KEY_KP_6;
        io.KeyMap[ImGuiKey_Keypad7] = GLFW_KEY_KP_7;
        io.KeyMap[ImGuiKey_Keypad8] = GLFW_KEY_KP_8;
        io.KeyMap[ImGuiKey_Keypad9] = GLFW_KEY_KP_9;
        io.KeyMap[ImGuiKey_KeypadDecimal] = GLFW_KEY_KP_DECIMAL;
        io.KeyMap[ImGuiKey_KeypadDivide] = GLFW_KEY_KP_DIVIDE;
        io.KeyMap[ImGuiKey_KeypadMultiply] = GLFW_KEY_KP_MULTIPLY;
        io.KeyMap[ImGuiKey_KeypadSubtract] = GLFW_KEY_KP_SUBTRACT;
        io.KeyMap[ImGuiKey_KeypadAdd] = GLFW_KEY_KP_ADD;
        io.KeyMap[ImGuiKey_KeypadEnter] = GLFW_KEY_KP_ENTER;
        io.KeyMap[ImGuiKey_KeypadEqual] = GLFW_KEY_KP_EQUAL;
        io.KeyMap[ImGuiKey_LeftShift] = GLFW_KEY_LEFT_SHIFT;
        io.KeyMap[ImGuiKey_LeftCtrl] = GLFW_KEY_LEFT_CONTROL;
        io.KeyMap[ImGuiKey_LeftAlt] = GLFW_KEY_LEFT_ALT;
        io.KeyMap[ImGuiKey_LeftSuper] = GLFW_KEY_LEFT_SUPER;
        io.KeyMap[ImGuiKey_RightShift] = GLFW_KEY_RIGHT_SHIFT;
        io.KeyMap[ImGuiKey_RightCtrl] = GLFW_KEY_RIGHT_CONTROL;
        io.KeyMap[ImGuiKey_RightAlt] = GLFW_KEY_RIGHT_ALT;
        io.KeyMap[ImGuiKey_RightSuper] = GLFW_KEY_RIGHT_SUPER;
        io.KeyMap[ImGuiKey_Menu] = GLFW_KEY_MENU;
        io.KeyMap[ImGuiKey_0] = GLFW_KEY_0;
        io.KeyMap[ImGuiKey_1] = GLFW_KEY_1;
        io.KeyMap[ImGuiKey_2] = GLFW_KEY_2;
        io.KeyMap[ImGuiKey_3] = GLFW_KEY_3;
        io.KeyMap[ImGuiKey_4] = GLFW_KEY_4;
        io.KeyMap[ImGuiKey_5] = GLFW_KEY_5;
        io.KeyMap[ImGuiKey_6] = GLFW_KEY_6;
        io.KeyMap[ImGuiKey_7] = GLFW_KEY_7;
        io.KeyMap[ImGuiKey_8] = GLFW_KEY_8;
        io.KeyMap[ImGuiKey_9] = GLFW_KEY_9;
        io.KeyMap[ImGuiKey_A] = GLFW_KEY_A;
        io.KeyMap[ImGuiKey_B] = GLFW_KEY_B;
        io.KeyMap[ImGuiKey_C] = GLFW_KEY_C;
        io.KeyMap[ImGuiKey_D] = GLFW_KEY_D;
        io.KeyMap[ImGuiKey_E] = GLFW_KEY_E;
        io.KeyMap[ImGuiKey_F] = GLFW_KEY_F;
        io.KeyMap[ImGuiKey_G] = GLFW_KEY_G;
        io.KeyMap[ImGuiKey_H] = GLFW_KEY_H;
        io.KeyMap[ImGuiKey_I] = GLFW_KEY_I;
        io.KeyMap[ImGuiKey_J] = GLFW_KEY_J;
        io.KeyMap[ImGuiKey_K] = GLFW_KEY_K;
        io.KeyMap[ImGuiKey_L] = GLFW_KEY_L;
        io.KeyMap[ImGuiKey_M] = GLFW_KEY_M;
        io.KeyMap[ImGuiKey_N] = GLFW_KEY_N;
        io.KeyMap[ImGuiKey_O] = GLFW_KEY_O;
        io.KeyMap[ImGuiKey_P] = GLFW_KEY_P;
        io.KeyMap[ImGuiKey_Q] = GLFW_KEY_Q;
        io.KeyMap[ImGuiKey_R] = GLFW_KEY_R;
        io.KeyMap[ImGuiKey_S] = GLFW_KEY_S;
        io.KeyMap[ImGuiKey_T] = GLFW_KEY_T;
        io.KeyMap[ImGuiKey_U] = GLFW_KEY_U;
        io.KeyMap[ImGuiKey_V] = GLFW_KEY_V;
        io.KeyMap[ImGuiKey_W] = GLFW_KEY_W;
        io.KeyMap[ImGuiKey_X] = GLFW_KEY_X;
        io.KeyMap[ImGuiKey_Y] = GLFW_KEY_Y;
        io.KeyMap[ImGuiKey_Z] = GLFW_KEY_Z;
        io.KeyMap[ImGuiKey_F1] = GLFW_KEY_F1;
        io.KeyMap[ImGuiKey_F2] = GLFW_KEY_F2;
        io.KeyMap[ImGuiKey_F3] = GLFW_KEY_F3;
        io.KeyMap[ImGuiKey_F4] = GLFW_KEY_F4;
        io.KeyMap[ImGuiKey_F5] = GLFW_KEY_F5;
        io.KeyMap[ImGuiKey_F6] = GLFW_KEY_F6;
        io.KeyMap[ImGuiKey_F7] = GLFW_KEY_F7;
        io.KeyMap[ImGuiKey_F8] = GLFW_KEY_F8;
        io.KeyMap[ImGuiKey_F9] = GLFW_KEY_F9;
        io.KeyMap[ImGuiKey_F10] = GLFW_KEY_F10;
        io.KeyMap[ImGuiKey_F11] = GLFW_KEY_F11;
        io.KeyMap[ImGuiKey_F12] = GLFW_KEY_F12;

        ImGui_ImplOpenGL3_Init("#version 410");
	}

	void imguiLayer::OnDetach()
	{
	}

	void imguiLayer::OnUpdate()
	{
        
        ImGuiIO& io = ImGui::GetIO();
        Application& app = Application::Get();
        io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

        float time = (float)glfwGetTime();
        io.DeltaTime = m_Time > 0.0 ? (time - m_Time) : (1.0f / 60.0f);
        m_Time = time;

        ImGui_ImplOpenGL3_NewFrame();
        ImGui::NewFrame();

        static bool show = true;
        ImGui::ShowDemoWindow(&show);

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void imguiLayer::OnEvent(Event& event)
	{
        EventDispatcher dispatcher(event);
        dispatcher.Dispatch<MouseButtonPressed>(GETEST_BIND_EVENT_FN(imguiLayer::OnMouseButtonPressedEvent));
        dispatcher.Dispatch<MouseButtonReleased>(GETEST_BIND_EVENT_FN(imguiLayer::OnMouseButtonReleasedEvent));
        dispatcher.Dispatch<MouseMovedEvent>(GETEST_BIND_EVENT_FN(imguiLayer::OnMouseMovedEvent));
        dispatcher.Dispatch<MouseScrolledEvent>(GETEST_BIND_EVENT_FN(imguiLayer::OnMouseScrolledEvent));
        dispatcher.Dispatch<KeyPressedEvent>(GETEST_BIND_EVENT_FN(imguiLayer::OnKeyPressedEvent));
        dispatcher.Dispatch<KeyReleasedEvent>(GETEST_BIND_EVENT_FN(imguiLayer::OnKeyReleasedEvent));
        dispatcher.Dispatch<WindowResizeEvent>(GETEST_BIND_EVENT_FN(imguiLayer::OnWindowResizeEvent));
        dispatcher.Dispatch<KeyTypedEvent>(GETEST_BIND_EVENT_FN(imguiLayer::OnKeyTypedEvent));


	}

    bool imguiLayer::OnMouseButtonPressedEvent(MouseButtonPressed& e)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.MouseDown[e.GetMouseButton()] = true;

        return false;
    }

    bool imguiLayer::OnMouseButtonReleasedEvent(MouseButtonReleased& e)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.MouseDown[e.GetMouseButton()] = false;

        return false;
    }

    bool imguiLayer::OnMouseMovedEvent(MouseMovedEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.MousePos = ImVec2(e.GetX(), e.GetY());

        return false;
    }

    bool imguiLayer::OnMouseScrolledEvent(MouseScrolledEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.MouseWheel += e.GetYOffset();
        io.MouseWheelH += e.GetXOffset();

        return false;
    }

    bool imguiLayer::OnKeyPressedEvent(KeyPressedEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.KeysDown[e.GetKeyCode()] = true;

        return false;
    }

    bool imguiLayer::OnKeyReleasedEvent(KeyReleasedEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.KeysDown[e.GetKeyCode()] = false;

        io.KeyCtrl = io.KeysDown[GLFW_KEY_LEFT_CONTROL] || io.KeysDown[GLFW_KEY_RIGHT_CONTROL];
        io.KeyAlt = io.KeysDown[GLFW_KEY_LEFT_ALT] || io.KeysDown[GLFW_KEY_RIGHT_ALT];
        io.KeyShift = io.KeysDown[GLFW_KEY_LEFT_SHIFT] || io.KeysDown[GLFW_KEY_RIGHT_SHIFT];
        io.KeySuper = io.KeysDown[GLFW_KEY_LEFT_SUPER] || io.KeysDown[GLFW_KEY_RIGHT_SUPER];
        return false;
    }

    bool imguiLayer::OnKeyTypedEvent(KeyTypedEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
        int keycode = e.GetKeyCode();
        if (keycode > 0 && keycode < 0x10000)
            io.AddInputCharacter((unsigned short)keycode);

        return false;
    }

    bool imguiLayer::OnWindowResizeEvent(WindowResizeEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.DisplaySize = ImVec2(e.GetWidth(), e.GetHeight());
        io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
        glViewport(0, 0, e.GetWidth(), e.GetHeight());

        return false;
    }

}