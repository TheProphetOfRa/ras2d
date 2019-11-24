//
//  InputManager.h
//  Chip8 Emulator
//
//  Created by David Hodgkinson on 12/11/2019.
//  Copyright © 2019 David Hodgkinson. All rights reserved.
//

#pragma once

#include "Controller/RenderManager.h"

#include <vector>

namespace Ras2D
{
    class Application;

    class InputManager
    {
    public:
        InputManager(Application* application);
        
        void ProcessInput(GLFWwindow window);
        
    private:
        std::vector<bool> _keys;
        
        Application* _application;
    };
}
