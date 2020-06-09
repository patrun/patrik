uniform sampler2D myTexture;
uniform float oznaci;

varying vec2 vTexCoord;

void main(void) {  
	vec4 red = vec4(0.0, 0.0, 0.0, 0.0);
    if(oznaci >= 1)
        red = vec4(1.0, 0.0, 0.0, 0.0);
	//vTexCoord.x = 0,05;
	
	gl_FragColor = (texture2D(myTexture, vTexCoord).rgba + red);
}