#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTex;

layout (location = 3) in vec3 aNormal;

// out variables to the fragment shader
out vec3 color;
// texture coordinates to the fragment shader
out vec2 texCoord;

out vec3 Normal;
out vec3 crntPos;

uniform mat4 camMatrix;
uniform mat4 model;


void main()
{
	crntPos = vec3(model * vec4(aPos, 1.0f));

	// apply scaling to the vertex position
	gl_Position = camMatrix * vec4(crntPos, 1.0);
	// pass the color and texture coordinates to the fragment shader
	color = aColor;
	// pass the texture coordinates to the fragment shader
	texCoord = aTex;
	Normal = aNormal;
}