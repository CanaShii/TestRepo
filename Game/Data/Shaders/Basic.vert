attribute vec2 a_Position;

uniform vec2 u_Offset;

void main()
{
     vec2 pos = a_Position + u_Offset;
  

  gl_Position = vec4( pos, 0, 1);
}