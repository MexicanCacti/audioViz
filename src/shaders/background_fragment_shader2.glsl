#version 430 core

uniform vec2 u_resolution;
uniform float u_time;

out vec4 fragColor;

void main(){
  vec2 st = gl_FragCoord.xy/u_resolution.xy;
  st.x *= u_resolution.x/u_resolution.y;
  vec3 color = vec3(0.720,0.714,0.400);
  float d = 0.0;

  // Remap the space to -1. to 1.
  st = st *2.-1.;

  // Make the distance field
  d = length( abs(st)-.3 );
  // d = length( min(abs(st)-.3,0.) );
  // d = length( max(abs(st)-.3,0.) );

  // Visualize the distance field
  float size = sin(u_time*0.4); // Frequency
  float border = 0.25; // "Light" Behind it
  color.rb += smoothstep(size+border,size+1e-7,d)-
                smoothstep(size+1.501,size+1e-7,d);
  fragColor = vec4(vec3(fract(d*color)),1.0);

  // Drawing with the distance field
  // gl_FragColor = vec4(vec3( step(.3,d) ),1.0);
  // gl_FragColor = vec4(vec3( step(.3,d) * step(d,.4)),1.0);
  // gl_FragColor = vec4(vec3( smoothstep(.3,.4,d)* smoothstep(.6,.5,d)) ,1.0);
}