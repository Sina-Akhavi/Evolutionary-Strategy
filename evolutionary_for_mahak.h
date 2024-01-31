#include <systemc.h>
#include <string.h>
#include <stdlib.h>  // For rand() and srand()


SC_MODULE(mahak) {
    
    const double PRICES_PER_UNIT[9] = {3, 1.67, 1.33, 1.29, 1.2, 0.78, 1, 1.5, 1.6};
    
    const int BAG_LIMIT = 15;
    
    const int OBJECT_NUMS = 9;

    const int MAX_WEIGHT_PER_OBJECT[9] = {2, 3, 6, 7, 5, 9, 3, 4, 5};

    const int MEMBER_NUM = 6;

    double population[6][9];

    double compute_price(int member_id) {
        double weights_of_member[OBJECT_NUMS];
        memcpy(weights_of_member, population[member_id], OBJECT_NUMS * sizeof(double));

        int i;
        double price = 0;
        for (i = 0; i < OBJECT_NUMS; i++) {
            price += weights_of_member[i] * PRICES_PER_UNIT[i];
        }

        return price;
    }

    void initialize_population() {

        srand(time(NULL));

        int i, j;

        for (i = 0; i < MEMBER_NUM; i++) {
            for (j = 0; j < OBJECT_NUMS; j++) {
                int randomNumber = rand() % (MAX_WEIGHT_PER_OBJECT[j] + 1);  // Generate random integer within range
                population[i][j] = randomNumber;
            }
        }
    }
    
    void print_population() {
        int i, j;
        
        char str[50] = "";
        for (i = 0; i < MEMBER_NUM; i++) {
            printf(" member %d has weights: ", i);
            for (j = 0; j < OBJECT_NUMS; j++) {
                printf("%f ", population[i][j]);
            }
            printf("\n");
        }

    }

    void test() {
        char str[50] = "";

        sprintf(str, "Bye %d", 13);

        cout << str << endl;
    }

    void check_and_repair_max_weight(int member_id) {
        int i;
        for (i = 0; i < OBJECT_NUMS; i++) {
            if (population[member_id][i] > MAX_WEIGHT_PER_OBJECT[i]) {
                population[member_id][i] = MAX_WEIGHT_PER_OBJECT[i];
            }
        }
    }

    SC_CTOR(mahak) {
        // SC_METHOD(print_prices);
    }

};