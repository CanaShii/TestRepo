attribute vec2 a_Position;
attribute vec2 a_UV;

uniform vec2 u_Scale;
uniform float u_Angle;
uniform vec2 u_Offset;
uniform float u_AspectRatio;
uniform vec2 u_uvScale;
uniform vec2 u_uvOffset;

varying vec2 v_UV;

void main()
{
	vec2 pos = a_Position;

	// Scale.
	pos *= u_Scale;
	
	// Rotate.
	float newX = cos(u_Angle)*pos.x + -sin(u_Angle)*pos.y;
	float newY = sin(u_Angle)*pos.x + cos(u_Angle)*pos.y;
	pos = vec2(newX, newY);
	
	// Translate.
	pos += u_Offset;

	// Correct for aspect ratio.
	pos *= vec4( u_AspectRatio, 1, 1, 1 );

	gl_Position = vec4( pos, 0, 1 );

	v_UV = a_UV * u_uvScale + u_uvOffset;
}
