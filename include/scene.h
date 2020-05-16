#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"

#include <obj/model.h>

typedef struct Scene
{
    Camera camera;
    Model model;
	Model model2;
	Model sun_model;
    Material material;
    GLuint texture_id1;
    GLuint texture_id2;
    GLuint sun;
    GLuint help;
	GLuint sky_texture_id;
	GLuint plane_texture_id;
	
} Scene;
typedef struct Model;
typedef struct Texture;
/**
 * Initialize the scene by loading models.
 */
void init_scene(Scene* scene);

/**
 * Set the lighting of the scene.
 */
void set_lighting();

void update_light(Scene* scene, double ertek);

/**
 * Set the current material.
 */
void set_material(const Material* material);

/**
 * Draw the scene objects.
 */
void draw_scene(const Scene* scene);

/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();

#endif /* SCENE_H */
