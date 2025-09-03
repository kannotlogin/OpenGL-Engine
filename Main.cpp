#include"Model.h"


const unsigned int width = 800;
const unsigned int height = 800;


int main()
{
	// Initialize GLFW
	glfwInit();

	// Configure GLFW
	// Set the OpenGL version to 3.3 and use the core profile
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a windowed mode window and its OpenGL context
	GLFWwindow* window = glfwCreateWindow(width, height, "OpenGL", NULL, NULL);
	// Check if the window was created successfully
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Make the window's context current
	glfwMakeContextCurrent(window);

	// Load OpenGL function pointers using GLAD
	gladLoadGL();

	// Set the viewport
	glViewport(0, 0, width, height);
	
	// Create shader program
	Shader shaderProgram("default.vert", "default.frag");

	// Light properties
	glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	glm::vec3 lightPos = glm::vec3(0.5f, 0.5f, 0.5f);
	glm::mat4 lightModel = glm::mat4(1.0f);
	lightModel = glm::translate(lightModel, lightPos);

	// Set the uniforms for the shaders
	shaderProgram.Activate();
	// Send the light color and position to the shader
	glUniform4f(glGetUniformLocation(shaderProgram.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(shaderProgram.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);

	// Enable depth testing
	glEnable(GL_DEPTH_TEST);

	Camera camera(width, height, glm::vec3(0.0f, 0.0f, 2.0f));

	Model model("models/wooden/scene.gltf");

	// Main loop
	while (!glfwWindowShouldClose(window))
	{
		// Set the clear color and clear the screen
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Handle camera inputs
		camera.Inputs(window);
		// Update and send the camera matrix to the shader
		camera.updateMatrix(45.0f, 0.1f, 100.0f);

		model.Draw(shaderProgram, camera);

		// Unbind the texture
		glfwSwapBuffers(window);
		// Poll for and process events
		glfwPollEvents();
	};

	// Deallocate resources
	shaderProgram.Delete();
	// Clean up and exit
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
};