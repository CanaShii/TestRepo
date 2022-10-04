Try out these fragment shaders.

- Add the .frag files to your project's data folder
- Create two triangles that cover the entire screen
- Create a shader in the Game class using your existing .vert and one of these .frag's
- The .frag files expect some (or all) of the following uniforms to be set:

uniform float iGlobalTime;   <- Set with the time since the game started
uniform vec4 iDate;          <- A vec4 for date/time, the shaders really only use the .w which need to be set with the same time as iGlobalTime
uniform vec3 iResolution;    <- The resolution of your screen, none of the frag files use the Z value, so just make sure the x/y are correct

These are pretty much just downloaded straight from shadertoy.com, I had to make some minor changes like:
- Setting gl_FragColor instead of returning a color.
- I added the uniform declarations at the top of each since ShaderToy generally does that for you behind the scenes.
