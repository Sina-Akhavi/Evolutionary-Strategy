#include <evolutionary_for_mahak.h>
#include <string.h>

// ------------------- MACROS -------------------
#define OBJECT_NUMBERS 9
#define P_POPULATION 4
#define MEMBER_NUMBERS 6
#define U 4

// ------------------ Global Variables ------------------
mahak mahak_obj("evolutionary_strategy");

// ------------------ Prototypes ------------------
void print_population(double population[][OBJECT_NUMBERS], int rows, int cols);

void clone_population(double cloned_population[][OBJECT_NUMBERS], int rows, int cols);

void evaluate();

double choose_best_price(double population[][OBJECT_NUMBERS], int m, int n);

void initialize();

void reproduce();

void repair();

void pick_best_u_individuals();

int sc_main(int argc, char* argv[]) {
    
    // initialize();

    // mahak_obj.print_population();

    // reproduce();

    // repair();

    // pick_best_u_individuals();

    // mahak_obj.print_population();
    // mahak_obj.print_T();

    // -------------------------- Test choose_best_price --------------------------
    initialize();
    mahak_obj.print_population();
    reproduce();

    mahak_obj.print_T();
    repair();
    printf("\n-----------------After Repair--------------------");

    mahak_obj.print_population();
    mahak_obj.print_T();

    pick_best_u_individuals();

    mahak_obj.print_population();

    return 0;
}


void print_population(double population[][OBJECT_NUMBERS], int rows, int cols) {
    int i, j;
    
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%f ", population[i][j]);
        }
        printf("\n");
    }
}

void clone_population(double cloned_population[][OBJECT_NUMBERS], int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            cloned_population[i][j] = mahak_obj.population[i][j];
        }
    }
}

void evaluate() {

    double cloned_population[P_POPULATION][OBJECT_NUMBERS];

    clone_population(cloned_population, P_POPULATION, OBJECT_NUMBERS);
    print_population(cloned_population, P_POPULATION, OBJECT_NUMBERS); 
}

double choose_best_price(double population[][OBJECT_NUMBERS], int m, int n) {
    int i;
    double max_sum = -100000; 
    for (i = 0; i < m; i++) {
    
        double sum = 0;
        int j;
        for (j = 0; j < n; j++) {
            sum += population[i][j] * mahak_obj.PRICES_PER_UNIT[j];
        }

        // printf("\nsum %d = %f\n", i, sum);

        if (sum > max_sum) {
            max_sum = sum;
        }
    }

    return max_sum;
}

void initialize() {
    mahak_obj.initialize_population();
}

void reproduce() {
    mahak_obj.reproduce();
}

void repair() {

    // int i;
    // for (i = 0; i < MEMBER_NUMBERS; i++) {
    //     mahak_obj.check_and_repair_max_weight_T(i);
    // }

    mahak_obj.check_bag_limitation_and_repair_T();

    // for (i = 0; i < P_POPULATION; i++) {
    //     mahak_obj.check_and_repair_max_weight_P(i);
    // }
    mahak_obj.check_bag_limitation_and_repair_P();
}


void pick_best_u_individuals() {
    int best_u_members[U];
    mahak_obj.pick_best_u_individuals(best_u_members, U);

    // int i;
    // printf("\n\n");
    // for (i = 0; i < U; i++) {
    //     printf("id = %d    ", best_u_members[i]);
    // }
    // printf("\n\n");

    mahak_obj.go_next_generation(best_u_members, U); 
}