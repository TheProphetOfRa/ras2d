//
//  InputManager.cpp
//  Chip8 Emulator
//
//  Created by David Hodgkinson on 12/11/2019.
//  Copyright © 2019 David Hodgkinson. All rights reserved.
//

#include "InputManager.h"

namespace Ras2D
{
    InputManager::InputManager(Application* application)
    : _application(application)
    {
        
    }

    void InputManager::ProcessInput(GLFWwindow* window)
    {
         glfwPollEvents();

         if (GLFW_PRESS == glfwGetKey(window, GLFW_KEY_ESCAPE))
         {
             glfwSetWindowShouldClose(window, 1);
         }

         _keys[0] = glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS;
         _keys[1] = glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS;
         _keys[2] = glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS;
         _keys[3] = glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS;
         _keys[4] = glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS;
         _keys[5] = glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS;
         _keys[6] = glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS;
         _keys[7] = glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS;
         _keys[8] = glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS;
         _keys[9] = glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS;
         _keys[10] = glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS;
         _keys[11] = glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS;
         _keys[12] = glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS;
         _keys[13] = glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS;
         _keys[14] = glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS;
         _keys[15] = glfwGetKey(window, GLFW_KEY_V) == GLFW_PRESS;

         return !glfwWindowShouldClose(window);
    }
}
