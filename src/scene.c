#include "scene.h"

#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

#include <obj/load.h>
#include <obj/draw.h>


double fenyero=0;

static int slices = 16;
static int stacks = 16;

float koalaX = 25.0f;
float sebesseg=.10;

float koala2X=0.0f;
float sebesseg2=.10;

float koala3X=0.0f;
float sebesseg3=.10;



void init_scene(Scene* scene)
{
	load_model(&(scene->model), "kenguru.obj");
    scene->texture_id1= load_texture("kenguru.jpg");

	load_model(&(scene->model2), "koala.obj");
    scene->texture_id2=load_texture("koala.jpg");

	scene->sky_texture_id = load_texture("hatter.jpg");
	scene->plane_texture_id = load_texture_plane("fold.png");

    load_model(&(scene->sun_model), "sun.obj");
    scene->sun = load_texture("sun.png");
    scene->help = load_texture("help.png");

	scene->material.ambient.red = 1.0;
    scene->material.ambient.green = 1.0;
    scene->material.ambient.blue = 1.0;

    scene->material.diffuse.red = 1.0;
    scene->material.diffuse.green = 1.0;
    scene->material.diffuse.blue = 1.0;

    scene->material.specular.red = 1.0;
    scene->material.specular.green = 1.0;
    scene->material.specular.blue = 1.0;

    scene->material.shininess = 6.0;
}

void set_lighting()
{


    float ambient_light[] = { 1.3f, 1.0f, 1.3f, 0.0f };
    float diffuse_light[] = { 1.5f+fenyero, 0.8f+fenyero, 0.2+fenyero, 0.0f+fenyero };
    float specular_light[] = { 0.0f, 0.0f, 3.0f, 0.0f };
    float position[] = { 1.0f, 1.0f, 1.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);


}

void set_material(const Material* material)
{
    float ambient_material_color[] = {
        material->ambient.red,
        material->ambient.green,
        material->ambient.blue
    };

    float diffuse_material_color[] = {
        material->diffuse.red,
        material->diffuse.green,
        material->diffuse.blue
    };

    float specular_material_color[] = {
        material->specular.red,
        material->specular.green,
        material->specular.blue
    };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);

    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(material->shininess));
}

void draw_scene(const Scene* scene)
{
    set_material(&(scene->material));
    set_lighting();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D,scene->sky_texture_id);//ég
    draw_skybox();
	glPopMatrix();

	glPushMatrix();

	glBindTexture(GL_TEXTURE_2D,scene->texture_id1);//kenguru
	glTranslatef(-5.0,0.0,0.0);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
	glScalef(0.5,0.5,0.5);
	draw_model(&(scene->model));
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D,scene->texture_id1);//kenguru
	glTranslatef(0.0,-5.0,0.0);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
	glScalef(0.5,0.5,0.5);
	draw_model(&(scene->model));
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D,scene->texture_id1);//kenguru
	glTranslatef(-10.0,0.0,0.0);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
	glScalef(0.5,0.5,0.5);
	draw_model(&(scene->model));
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D,scene->texture_id1);//kenguru
	glTranslatef(-15.0,-5.0,0.0);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
	glScalef(0.5,0.5,0.5);
	draw_model(&(scene->model));
	glPopMatrix();

		glPushMatrix();
	glBindTexture(GL_TEXTURE_2D,scene->texture_id1);//kenguru
	glTranslatef(-25.0,-5.0,0.0);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
	glScalef(0.5,0.5,0.5);
	draw_model(&(scene->model));
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D,scene->texture_id1);//kenguru
	glTranslatef(20.0,-5.0,0.0);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
	glScalef(0.5,0.5,0.5);
	draw_model(&(scene->model));
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D,scene->texture_id1);//kenguru
	glTranslatef(25.0,0,0.0);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
	glScalef(0.5,0.5,0.5);
	draw_model(&(scene->model));
	glPopMatrix();


	glPushMatrix();

	glBindTexture(GL_TEXTURE_2D,scene->texture_id2);//kenguru

	glTranslatef(40.0,20.0, 0.0);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
	glScalef(1.0,1.0,1.0);
	draw_model(&(scene->model2));
	glPopMatrix();
	glPushMatrix();

	glBindTexture(GL_TEXTURE_2D,scene->texture_id2);//kenguru

	glTranslatef(40.0,10.0, 0.0);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
	glScalef(1.0,1.0,1.0);
	draw_model(&(scene->model2));
	glPopMatrix();

	glPushMatrix();//mozgó koala

        if(koala3X > 40.0 && sebesseg3 > 0) {
            sebesseg3 = -.05;
        }

        if(koala3X < -40.0 && sebesseg3 < 0) {
            sebesseg3 = .02;
        }

       koala3X += sebesseg3;

        glTranslatef(10.0, koala3X, 0.0);

        if(sebesseg3 > 0) {
            glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
        } else {
            glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
        }

        glScalef(1.0, 1.0, 1.0);

       glBindTexture(GL_TEXTURE_2D,scene->texture_id2);
       draw_model(&(scene->model2));
	   glPopMatrix();


		glPushMatrix();//mozgó koala

        if(koalaX > 40.0 && sebesseg > 0) {
            sebesseg = -.07;
        }

        if(koalaX < 10.0 && sebesseg < 0) {
            sebesseg = .005;
        }

       koalaX += sebesseg;

        glTranslatef(-10.0, koalaX, 0.0);

        if(sebesseg > 0) {
            glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
        } else {
            glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
        }

        glScalef(1.0, 1.0, 1.0);

       glBindTexture(GL_TEXTURE_2D,scene->texture_id2);
       draw_model(&(scene->model2));
	   glPopMatrix();




		glPushMatrix();//mozgó koala

        if(koala2X > 30.0 && sebesseg2 > 0) {
            sebesseg2 = -.02;
        }

        if(koala2X < -40.0 && sebesseg2 < 0) {
            sebesseg2 = .02;
        }

       koala2X += sebesseg2;

        glTranslatef(-20.0, koala2X, 0.0);

        if(sebesseg2 > 0) {
            glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
        } else {
            glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
        }

        glScalef(1.0, 1.0, 1.0);


       glBindTexture(GL_TEXTURE_2D,scene->texture_id2);
       draw_model(&(scene->model2));
	   glPopMatrix();

    glPushMatrix();
	glBindTexture(GL_TEXTURE_2D,scene->sun);
	const double t = glutGet(GLUT_ELAPSED_TIME) / 5000.0;//nap
    const double a = t*90.0;

    glTranslated(0,0,45);
    glRotated(60,1,0,0);
    glRotated(a,0,0,1);
	glScalef(10.0,10.0,10.0);
	//glutWireSphere(1,slices,stacks);
	draw_model(&(scene->sun_model));
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D,scene->plane_texture_id);
	draw_polygon();
    glPopMatrix();

	glBindTexture(GL_TEXTURE_2D,scene->help);
}

void update_light(Scene* scene, double ertek){
	fenyero+=ertek;
}

void draw_polygon(){

	glBegin(GL_POLYGON);//alap
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
	glTexCoord2f(1,1);
    glVertex3d(-50, -50, 0.0);

	glTexCoord2f(0,1);
    glVertex3d(-50, 50, 0.0);

    glTexCoord2f(0,0);
    glVertex3d(50, 50, 0.0);

	glTexCoord2f(1,0);
    glVertex3d(50, -50, 0.0);

    glEnd();}


void draw_skybox()
{
    double theta, phi1, phi2;
    double x1, y1, z1;
    double x2, y2, z2;
    double u, v1, v2;

    int n_slices, n_stacks;
    double radius;
    int i, k;

    n_slices = 12;
    n_stacks = 6;
    radius = 50;

    glPushMatrix();

    glScaled(radius, radius, radius);

    glColor3f(1, 1, 1);

	glBegin(GL_TRIANGLE_STRIP);

    for (i = 0; i < n_stacks; ++i) {
        v1 = (double)i / n_stacks;
        v2 = (double)(i + 1) / n_stacks;
        phi1 = v1 * M_PI / 2.0;
        phi2 = v2 * M_PI / 2.0;
        for (k = 0; k <= n_slices; ++k) {
            u = (double)k / n_slices;
            theta = u * 2.0 * M_PI;
            x1 = cos(theta) * cos(phi1);
            y1 = sin(theta) * cos(phi1);
            z1 = sin(phi1);
            x2 = cos(theta) * cos(phi2);
            y2 = sin(theta) * cos(phi2);
            z2 = sin(phi2);
            glTexCoord2d(u, 1.0 - v1);
            glVertex3d(x1, y1, z1);
            glTexCoord2d(u, 1.0 - v2);
            glVertex3d(x2, y2, z2);
        }
    }

    glEnd();

    glPopMatrix();
}
