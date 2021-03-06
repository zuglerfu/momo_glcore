//
//  GLProgram.hpp
//  GLProgram
//
//  Created by zhuang yusong on 2017/3/4.
//  Copyright © 2017年 zhuang yusong. All rights reserved.
//

#ifndef GLProgram_hpp
#define GLProgram_hpp
#include "GLCore.h"
#include <string>
#include <map>
using namespace std;
#if defined(USE_GLEW)
#include <GL/glew.h>
#else
#include <GLES3/gl3.h>
#include <GL/glu.h>
#include <GL/glext.h>
#endif
#include "GLShader.h"
#include "GLUniform.h"
#include "GLAttribute.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

class GLCORE GLProgram{
    
public:
    
    GLProgram();
    
    void create();
    
    void attachShader(GLuint shader);
    
    void attachShader(GLShader& shader);
    
    void link();
    
    void use();
    
    GLuint getProgram();
    
    std::string getError();
    
    GLUniform* getUniform(const std::string& name);
    
    GLAttribute* getAttribute(const std::string& name);
    
    void setInt(const std::string& name, int value);
    
    void setFloat(const std::string& name, float value);
    
    void setMat4(const std::string& name, const glm::mat4& value);
    
    void setVec3(const std::string& name, const glm::vec3& value);
    
protected:
    
    GLuint m_program;
    
    std::string m_error;
    
    map<string, GLUniform*> m_unifrom;
    
    map<string, GLAttribute*> m_attribute;
};


#endif /* GLShader_hpp */
