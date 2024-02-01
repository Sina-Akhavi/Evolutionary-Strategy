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

    void check_and_repair_max_weight(int member_id) {
        int i;
        for (i = 0; i < OBJECT_NUMS; i++) {
            if (population[member_id][i] > MAX_WEIGHT_PER_OBJECT[i]) {
                population[member_id][i] = MAX_WEIGHT_PER_OBJECT[i];
            }
        }
    }

    void pick_best_members_as_parents (int* best_members_ids) {
        int parents_nums = 2;
        // int* best_members_ids = (int*)malloc(parents_nums * sizeof(int)); 

        int max1 = -1000000;
        int max2 = -1000000;

        int max1_id = -1;
        int max2_id = -1;

        int i;
        for (i = 0; i < MEMBER_NUM; i++) {
            double price_i = compute_price(i);
            printf("member %d - price= %f\n", i, price_i);
            if (price_i > max1) {
                max2 = max1;
                max1 = price_i;

                max2_id = max1_id;
                max1_id = i;
            }
            else if (price_i > max2) {
                max2 = price_i;
                max2_id = i;
            }
        }

        best_members_ids[0] = max1_id;
        best_members_ids[1] = max2_id;
    }

    void do_crossover(int m1_id, int m2_id) {
        double* best_member1_weights = population[m1_id];
        double* best_member2_weights = population[m2_id];

        srand(time(NULL));
        int crossover_point = rand() % (OBJECT_NUMS + 1);
        printf("crossover point= %d\n", crossover_point);

        int i;
        for (i = crossover_point; i < OBJECT_NUMS; i++) {
            double temp = best_member1_weights[i];
            best_member1_weights[i] = best_member2_weights[i];
            best_member2_weights[i] = temp;
        }
    }

    void pick_best_u_individuals(int *best_u_member_ids, int u) {
        int best_u_member_prices[u];
        int i;

        for (i = 0; i < u; i++) {
            best_u_member_prices[i] = -100000;
            best_u_member_ids[i] = -1;
        }

        for (i = 0; i < MEMBER_NUM; i++) {
            double price_i = compute_price(i);

            int j;
            int flag = 1;
            for (j = 0; j < u && flag == 1; j++) {
                if  (price_i > best_u_member_prices[j]) {
                    int q;
                    for (q = u - 1; q >= j; q--) {
                        if (q == j) {
                            best_u_member_prices[q] = price_i;
                            best_u_member_ids[q] = i;
                            flag = -1;
                            break;
                        } else {
                            best_u_member_prices[q] = best_u_member_prices[q - 1];
                            best_u_member_ids[q] = best_u_member_ids[q - 1];
                        }
                    }
                }
            }
        } 
        
        
    }

    void check_bag_limitation_and_repair_member(double* weights) {
        
        double sum = 0;
        int i;
        for (i = 0; i < OBJECT_NUMS; i++) {
            sum += weights[i];
        }

        if (sum < BAG_LIMIT) 
            return;
        
        for (i = 0; i < OBJECT_NUMS; i++) {
            if (weights[i] > 0 && weights[i] < 0.5) 
                weights[i] = 0;
            else if (weights[i] > 0.5)
                weights[i] -= 0.5;
        }

        return check_bag_limitation_and_repair_member(weights);
    }

    void check_bag_limitation_and_repair_population() {
        int i;
        for (i = 0; i < MEMBER_NUM; i++) {
            check_bag_limitation_and_repair_member(population[i]);
        }
    }

    SC_CTOR(mahak) {
        // SC_METHOD(print_prices);
    }
    
};

