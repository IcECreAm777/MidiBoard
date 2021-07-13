
#include <forward_list>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "GridManager.h"
#include "External/imgui/imgui.h"
#include "External/imgui/imgui_impl_glfw.h"
#include "External/imgui/imgui_impl_opengl3.h"

#define INITIAL_WIDTH 1500
#define INITIAL_HEIGHT 800
#define MIN_WIDTH 800
#define MIN_HEIGHT 600

auto grid_manager = GridManager();

// callback method for resizing the window
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
    glfwGetWindowSize(window, &width, &height);
    grid_manager.RecalculateWindowsSize(width, height);
}

int main()
{
    //initialize open gl window
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(INITIAL_WIDTH, INITIAL_HEIGHT, "MidiBoard",
        nullptr, nullptr);
    if(window == nullptr)
    {
        std::cout << "Failed to create GLFW window. Aborting Program." << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // initialize GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // setup viewport
    glViewport(0, 0, INITIAL_WIDTH, INITIAL_HEIGHT);
    glfwSetWindowSizeLimits(window, MIN_WIDTH, MIN_HEIGHT,
        GLFW_DONT_CARE, GLFW_DONT_CARE);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    // Setup Platform/Renderer bindings
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init();
    // Setup Dear ImGui style
    ImGui::StyleColorsDark();

    int width, height;
    glfwGetWindowSize(window, &width, &height);
    grid_manager.RecalculateWindowsSize(width, height);
    
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT);

        // feed inputs to dear imgui, start new frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        grid_manager.DrawWindows();

        // Render dear imgui into screen
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        
        glfwSwapBuffers(window);
        glfwPollEvents();   
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    
    glfwTerminate();
    return 0;
}

