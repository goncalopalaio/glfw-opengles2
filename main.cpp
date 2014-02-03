//#define GLFW_INCLUDE_ES2 1

#include <GLFW/glfw3.h>
#include <iostream>
#include <cstdlib>
using namespace std;


double gStartTimeFPS=glfwGetTime();
double gFrameCount=0;
void showFPS() {
    double currentTime=glfwGetTime();
    gFrameCount++;
    if(currentTime-gStartTimeFPS>=1.0) {
        std::cout<<gFrameCount<<" FPS"<<std::endl;
        gFrameCount=0;
        gStartTimeFPS=glfwGetTime();
    }
}
void init() {
}
void update() {
}
void render() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.4,0.4,1.0,1.0);
}
void mainLoop() {
    update();
    render();
}
static void error_callback(int error, const char* description)
{
    cerr<<description<<endl;
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}
int main(void)
{
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);

    glfwWindowHint( GLFW_CLIENT_API, GLFW_OPENGL_ES_API );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 2 );

    window = glfwCreateWindow(640, 480, "Window Title", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(1);
    }
    glfwMakeContextCurrent(window);

    if (glfwExtensionSupported("GLX_EXT_create_context_es2_profile"))
    {
        cout<<"GLX_EXT_create_context_es2_profile Supported"<<endl;
    }
    
    cout<<glGetString(GL_VERSION)<<endl;
    glfwSetKeyCallback(window, key_callback);
    init();

    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float) height;
        glViewport(0, 0, width, height);

        mainLoop();
        showFPS();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}

