uniform mat4 transormation;
uniform mat4 modelview_matrix;
uniform mat4 projection_matrix;

varying vec2 vTexCoord;

void main(void)
{
	vTexCoord = gl_MultiTexCoord0.xy;
	
	gl_Position = projection_matrix * modelview_matrix * transormation * gl_Vertex;
}