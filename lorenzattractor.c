#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void renderLorenz () {
    double x = 1.25;
    double y = 2.22;
    double z = 3.2111;
    double dt = 0.025;
    
    FILE *lorenzptr = fopen ("lorenz_data.dat", "w");
    if (lorenzptr == NULL) {
        printf("Unable to open file.\n");
        return;
    }

    for (float t = 0; t < 150.0; t += dt) {
        x += (10.0 * (y - x)) * dt;
        y += ((28.0*x) - y - (x*z)) * dt;
        z += ((x*y) - ((8.0/3.0) * z)) * dt;
        fprintf(lorenzptr, "%lf %lf %lf\n", x, y, z);
    }
    fclose(lorenzptr);
}

int main () {
    renderLorenz();
    return 0;
}
