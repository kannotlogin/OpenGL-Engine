#version 330 core
// Fragment shader
out vec4 FragColor;

in vec3 color;
//in vec4 vertexColor;
in vec2 texCoord;

//in vec3 normal;
uniform sampler2D tex0;

void main()
{	//FragColor = vec4(color, 1.0);
	FragColor = texture(tex0, texCoord);
}