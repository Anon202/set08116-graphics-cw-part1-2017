#include <glm\glm.hpp>
#include <graphics_framework.h>

using namespace std;
using namespace graphics_framework;
using namespace glm;

map<string, mesh> meshes;
effect eff;
array <texture, 15> texs;
geometry geom;
free_camera cam;
target_camera cam2;
directional_light light;
double cursor_x = 0.0;
double cursor_y = 0.0;
bool initialise()
{
	//set input mode
	glfwSetInputMode(renderer::get_window(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	//capture initial mouse position
	glfwGetCursorPos(renderer::get_window(), &cursor_x, &cursor_y);

	return true;
}

bool load_content()
{
	//create mesh for the plane
	meshes["plane"] = mesh(geometry_builder::create_plane());
	// Create scene
	meshes["ground"] = mesh(geometry_builder::create_box());
	meshes["pool"] = mesh(geometry_builder::create_box());
	meshes["water"] = mesh(geometry_builder::create_box());
	meshes["dive-board"] = mesh(geometry_builder::create_box());
	meshes["filter-1(right)"] = mesh(geometry_builder::create_box());
	meshes["filter-2(bottom)"] = mesh(geometry_builder::create_box());
	meshes["filter-3(left)"] = mesh(geometry_builder::create_box());
	meshes["filter-4(top)"] = mesh(geometry_builder::create_box());
	meshes["grass-1(right)"] = mesh(geometry_builder::create_box());
	meshes["grass-2(bottom)"] = mesh(geometry_builder::create_box());
	meshes["grass-3(left)"] = mesh(geometry_builder::create_box());
	meshes["grass-4(top)"] = mesh(geometry_builder::create_box());




	// Transform objects
	//ground
	meshes["ground"].get_transform().scale = vec3(35.0f, 12.0f, 60.0f);
	meshes["ground"].get_transform().translate(vec3(20.0f, 0.0f, 20.0f));
	meshes["ground"].get_material().set_emissive(vec4(0.0f, 0.0f, 0.0f, 1.0f));
	meshes["ground"].get_material().set_specular(vec4(1.0f, 1.0f, 1.0f, 1.0f));
	meshes["ground"].get_material().set_shininess(100.0);
	meshes["ground"].get_material().set_diffuse(vec4(1.0f, 1.0f, 1.0f, 1.0f));
	//pool is 5x smaller than the ground
	meshes["pool"].get_transform().scale = vec3(7.0f,12.0f,12.0f);
	meshes["pool"].get_transform().translate(vec3(20.0f, 0.3f, 20.0f));
	meshes["pool"].get_material().set_emissive(vec4(0.0f, 0.0f, 0.0f, 1.0f));
	meshes["pool"].get_material().set_specular(vec4(1.0f, 1.0f, 1.0f, 1.0f));
	meshes["pool"].get_material().set_shininess(25.0);
	meshes["pool"].get_material().set_diffuse(vec4(1.0f, 1.0f, 1.0f, 1.0f));
	//water is -1 of the pool
	meshes["water"].get_transform().scale = vec3(6.0f, 12.0f, 11.0f);
	meshes["water"].get_transform().translate(vec3(20.0f, 0.5f, 20.0f));
	meshes["water"].get_material().set_emissive(vec4(0.0f, 0.0f, 0.0f, 1.0f));
	meshes["water"].get_material().set_specular(vec4(1.0f, 1.0f, 1.0f, 1.0f));
	meshes["water"].get_material().set_shininess(30.0);
	meshes["water"].get_material().set_diffuse(vec4(1.0f, 1.0f, 1.0f, 1.0f));
	//dive-board is -5 than the pool and back by 5
	meshes["dive-board"].get_transform().scale = vec3(1.0f, 0.1f, 3.0f);
	meshes["dive-board"].get_transform().translate(vec3(20.0f, 6.55f, 15.0f));
	meshes["dive-board"].get_material().set_emissive(vec4(0.0f, 0.0f, 0.0f, 1.0f));
	meshes["dive-board"].get_material().set_specular(vec4(1.0f, 1.0f, 1.0f, 1.0f));
	meshes["dive-board"].get_material().set_shininess(40.0);
	meshes["dive-board"].get_material().set_diffuse(vec4(1.0f, 1.0f, 1.0f, 1.0f));
	//filer1
	meshes["filter-1(right)"].get_transform().scale = vec3(1.0f, 0.5f, 11.0f);
	meshes["filter-1(right)"].get_transform().translate(vec3(16.5f, 6.25f, 20.0f));
	meshes["filter-1(right)"].get_material().set_emissive(vec4(0.0f, 0.0f, 0.0f, 1.0f));
	meshes["filter-1(right)"].get_material().set_specular(vec4(1.0f, 1.0f, 1.0f, 1.0f));
	meshes["filter-1(right)"].get_material().set_shininess(50.0);
	meshes["filter-1(right)"].get_material().set_diffuse(vec4(1.0f, 1.0f, 1.0f, 1.0f));
	//filter2
	meshes["filter-2(bottom)"].get_transform().scale = vec3(8.0f, 0.5f, 1.0f);
	meshes["filter-2(bottom)"].get_transform().translate(vec3(20.0f, 6.25f, 14.0f));
	meshes["filter-2(bottom)"].get_material().set_emissive(vec4(0.0f, 0.0f, 0.0f, 1.0f));
	meshes["filter-2(bottom)"].get_material().set_specular(vec4(1.0f, 1.0f, 1.0f, 1.0f));
	meshes["filter-2(bottom)"].get_material().set_shininess(50.0);
	meshes["filter-2(bottom)"].get_material().set_diffuse(vec4(1.0f, 1.0f, 1.0f, 1.0f));
	//filter3
	meshes["filter-3(left)"].get_transform().scale = vec3(1.0f, 0.5f, 11.0f);
	meshes["filter-3(left)"].get_transform().translate(vec3(23.5f, 6.25f, 20.0f));
	meshes["filter-3(left)"].get_material().set_emissive(vec4(0.0f, 0.0f, 0.0f, 1.0f));
	meshes["filter-3(left)"].get_material().set_specular(vec4(1.0f, 1.0f, 1.0f, 1.0f));
	meshes["filter-3(left)"].get_material().set_shininess(50.0);
	meshes["filter-3(left)"].get_material().set_diffuse(vec4(1.0f, 1.0f, 1.0f, 1.0f));
	//filter4
	meshes["filter-4(top)"].get_transform().scale = vec3(8.0f, 0.5f, 1.0f);
	meshes["filter-4(top)"].get_transform().translate(vec3(20.0f, 6.25f, 26.0f));
	meshes["filter-4(top)"].get_material().set_emissive(vec4(0.0f, 0.0f, 0.0f, 1.0f));
	meshes["filter-4(top)"].get_material().set_specular(vec4(1.0f, 1.0f, 1.0f, 1.0f));
	meshes["filter-4(top)"].get_material().set_shininess(50.0);
	meshes["filter-4(top)"].get_material().set_diffuse(vec4(1.0f, 1.0f, 1.0f, 1.0f));
	//grass1
	meshes["grass-1(right)"].get_transform().scale = vec3(13.5f, 0.5f, 60.0f);
	meshes["grass-1(right)"].get_transform().translate(vec3(9.25f, 6.25f, 20.0f));
	meshes["grass-1(right)"].get_material().set_emissive(vec4(0.0f, 0.0f, 0.0f, 1.0f));
	meshes["grass-1(right)"].get_material().set_specular(vec4(1.0f, 1.0f, 1.0f, 1.0f));
	meshes["grass-1(right)"].get_material().set_shininess(75.0);
	meshes["grass-1(right)"].get_material().set_diffuse(vec4(1.0f, 1.0f, 1.0f, 1.0f));
	//grass2
	meshes["grass-2(bottom)"].get_transform().scale = vec3(35.0f, 0.5f, 23.5f);
	meshes["grass-2(bottom)"].get_transform().translate(vec3(20.0f, 6.25f, 1.75f));
	meshes["grass-2(bottom)"].get_material().set_emissive(vec4(0.0f, 0.0f, 0.0f, 1.0f));
	meshes["grass-2(bottom)"].get_material().set_specular(vec4(1.0f, 1.0f, 1.0f, 1.0f));
	meshes["grass-2(bottom)"].get_material().set_shininess(75.0);
	meshes["grass-2(bottom)"].get_material().set_diffuse(vec4(1.0f, 1.0f, 1.0f, 1.0f));
	//grass3
	meshes["grass-3(left)"].get_transform().scale = vec3(13.5f, 0.5f, 60.0f);
	meshes["grass-3(left)"].get_transform().translate(vec3(30.75f, 6.25f, 20.0f));
	meshes["grass-3(left)"].get_material().set_emissive(vec4(0.0f, 0.0f, 0.0f, 1.0f));
	meshes["grass-3(left)"].get_material().set_specular(vec4(1.0f, 1.0f, 1.0f, 1.0f));
	meshes["grass-3(left)"].get_material().set_shininess(75.0);
	meshes["grass-3(left)"].get_material().set_diffuse(vec4(1.0f, 1.0f, 1.0f, 1.0f));
	//grass4
	meshes["grass-4(top)"].get_transform().scale = vec3(35.0f, 0.5f, 23.5f);
	meshes["grass-4(top)"].get_transform().translate(vec3(20.0f, 6.25f, 38.25f));
	meshes["grass-4(top)"].get_material().set_emissive(vec4(0.0f, 0.0f, 0.0f, 1.0f));
	meshes["grass-4(top)"].get_material().set_specular(vec4(1.0f, 1.0f, 1.0f, 1.0f));
	meshes["grass-4(top)"].get_material().set_shininess(75.0);
	meshes["grass-4(top)"].get_material().set_diffuse(vec4(1.0f, 1.0f, 1.0f, 1.0f));
	
	
	// Load texture
	texs[0] = texture("textures/dive-board.png");
	texs[1] = texture("textures/filter_1.png");
	texs[2] = texture("textures/filter_2.png");
	texs[3] = texture("textures/filter_3.png");
	texs[4] = texture("textures/filter_4.png");
	texs[5] = texture("textures/grass_1.png");
	texs[6] = texture("textures/grass_2.png");
	texs[7] = texture("textures/grass_3.png");
	texs[8] = texture("textures/grass_4.png");
	texs[9] = texture("textures/ground.png");
	texs[10] = texture("textures/plane.png");
	texs[11] = texture("textures/pool.png");
	texs[12] = texture("textures/water.png");
	
	// ambient intensity (0.3, 0.3, 0.3)
	light.set_ambient_intensity(vec4(0.3, 0.3, 0.3, 1.0f));
	// Light colour white
	light.set_light_colour(vec4(1.0f, 1.0f, 1.0f, 1.0f));
	// Light direction (1.0, 1.0, -1.0)
	light.set_direction(vec3(1.0f, 1.0f, -1.0f));

	// Load in shaders
	eff.add_shader("shaders/phong.frag", GL_FRAGMENT_SHADER);
	eff.add_shader("shaders/phong.vert", GL_VERTEX_SHADER);
	// Build effect
	eff.build();

	// Set camera properties
	cam.set_position(vec3(0.0f, 10.0f, 0.0f));
	cam.set_target(vec3(0.0f, 0.0f, 0.0f));
	cam.set_projection(quarter_pi<float>(), renderer::get_screen_aspect(), 0.1f, 1000.0f);
	return true;
}



bool update(float delta_time) 
{
	// The ratio of pixels to rotation - remember the fov
	static double ratio_width = quarter_pi<float>() / static_cast<float>(renderer::get_screen_width());
	static double ratio_height =
		(quarter_pi<float>() *
		(static_cast<float>(renderer::get_screen_height()) / static_cast<float>(renderer::get_screen_width()))) /
		static_cast<float>(renderer::get_screen_height());

	double current_x;
	double current_y;
	// *********************************
	// Get the current cursor position
	glfwGetCursorPos(renderer::get_window(), &current_x, &current_y);
	// Calculate delta of cursor positions from last frame
	double delta_x = current_x - cursor_x;
	double delta_y = current_y - cursor_y;

	// Multiply deltas by ratios - gets actual change in orientation
	delta_x = delta_x*ratio_width;
	delta_y = delta_y*ratio_height;

	// Rotate cameras by delta
	//delta_y - x-axis rotation
	// delta_x - y-axis rotation
	cam.rotate(delta_x, delta_y);

	//use the keyboard to go to set places-1234
		if (glfwGetKey(renderer::get_window(), '1')) 
		{
			
			cam.set_position(vec3(20.0, 8, 15.0));
			
		}
	if (glfwGetKey(renderer::get_window(), '2')) 
	{
		cam.set_position(vec3(20.0, 8, 16));
	}
	if (glfwGetKey(renderer::get_window(), '3'))
	{
		cam.set_position(vec3(20, 9, 18));
	}
	if (glfwGetKey(renderer::get_window(), '4')) 
	{
		cam.set_position(vec3(20, 9.5, 18.5));
	}
	if (glfwGetKey(renderer::get_window(), '5'))
	{
		cam.set_position(vec3(20, 10, 19.5));
	}
	if (glfwGetKey(renderer::get_window(), '6'))
	{
		cam.set_position(vec3(20, 9.5, 19.5));
	}
	if (glfwGetKey(renderer::get_window(), '7'))
	{
		cam.set_position(vec3(20, 9.0, 19.8));
	}
	if (glfwGetKey(renderer::get_window(), '8'))
	{
		cam.set_position(vec3(20, 8, 19.8));
	}
	if (glfwGetKey(renderer::get_window(), '9'))
	{
		cam.set_position(vec3(20, 6, 20));
	}
	if (glfwGetKey(renderer::get_window(), '0'))
	{
		cam.set_position(vec3(20, 5.5, 21.5));
	}

	// Use keyboard to move the camera - WSAD
	if (glfwGetKey(renderer::get_window(), GLFW_KEY_W))
	{
		cam.move(vec3(0.0f, 0.0f, 1.0f));
	}
	if (glfwGetKey(renderer::get_window(), GLFW_KEY_S))
	{
		cam.move(vec3(0.0f, 0.0f, -1.0f));
	}
	if (glfwGetKey(renderer::get_window(), GLFW_KEY_A))
	{
		cam.move(vec3(-1.0f, 0.0f, 0.0f));
	}
	if (glfwGetKey(renderer::get_window(), GLFW_KEY_D))
	{
		cam.move(vec3(1.0f, 0.0f, 0.0f));
	}


	// Update the camera
	cam.update(delta_time);
	// Update cursor pos
	cursor_x = current_x;
	cursor_y = current_y;
	return true;
}

bool render()
{
	int i = 0;
	for (auto &e: meshes)
	{
		auto m = e.second;
		// Bind effect
		renderer::bind(eff);
		// Create MVP matrix
		mat4 M = m.get_transform().get_transform_matrix();
		auto V = cam.get_view();
		auto P = cam.get_projection();
		auto MVP = P * V * M;
		auto N = transpose(inverse(M*V));
		// Set MVP matrix uniform
		glUniformMatrix4fv(eff.get_uniform_location("MVP"), 1, GL_FALSE, value_ptr(MVP));
		// set M uniform
		glUniformMatrix4fv(eff.get_uniform_location("M"), 1, GL_FALSE, value_ptr(M));
		// Set N matrix uniform - remember - 3x3 matrix
		glUniformMatrix3fv(eff.get_uniform_location("N"), 1, GL_FALSE, value_ptr(N));
		// Bind material
		renderer::bind(m.get_material(), "mat");
		// Bind light
		renderer::bind(light, "light");
		renderer::bind(texs[i], i);
		//set tex uniform
		glUniform1i(eff.get_uniform_location("tex"), i);
		// Set eye position - Get this from active camera
		glUniform3fv(eff.get_uniform_location("eye_pos"), 1, value_ptr(cam.get_position()));
		//render the meshes
		renderer::render(m);
		i++;
		
	}
	return true;
}

void main() 
{
	// Create application
	app application("Graphics Coursework");
	// Set load content, update and render methods
	application.set_load_content(load_content);
	application.set_initialise(initialise);
	application.set_update(update);
	application.set_render(render);
	// Run application
	application.run();
}



