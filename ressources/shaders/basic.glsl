//shader vertex
#version 330 core
layout (location = 0) in vec3 vertex_modelspace;

out vec3 vertex;

void main()
{
    gl_Position = vec4(vertex_modelspace, 1.0);
    vertex = vertex_modelspace;
};


//shader fragment
#version 330 core
out vec4 color;
in vec3 vertex;

void main()
{    
    color = vec4(1.0, 0.0, 0.0, 1.0);
}