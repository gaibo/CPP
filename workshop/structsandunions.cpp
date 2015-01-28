struct circle {
	int radius;									// radius of circle in pixels
};
struct rectangle {
	int height, width;							// size of rectangle in pixels
};
struct triangle {
	int base;									// length of the triangle's base in pixels
	int height;									// height of the triangle in pixels
};

const int SHAPE_CIRCLE = 0;						// shape is a circle
const int SHAPE_RECTANGLE = 1;					// shape is a rectangle
const int SHAPE_TRIANGLE = 2;					// shape is a triangle

struct shape {
	int kind;									// what kind of shape is stored
	union shape_union {							// union to hold shape information
		struct circle	circle_data;			// data for a circle
		struct rectangle	rectangle_data;		// data for a rectangle
		struct triangle	triangle_data;			// data for a triangle
	} data;
};

struct shape a_shape;
// this is a circle
a_shape.kind = SHAPE_CIRCLE;
a_shape.data.circle_data.radius = 50;			// define the radius of the circle
