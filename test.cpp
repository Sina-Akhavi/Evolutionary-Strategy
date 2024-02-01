#include <string.h>
#include "evolutionary_for_mahak.h"

int sc_main(int argc, char* argv[]) {
    // mahak evol1("evolutionary_strategy");
    // evol1.initialize_population();
    // evol1.print_population();
    // ** test check_and_repair_max_weight **

    // mahak evol1("evolutionary_strategy");
    // evol1.initialize_population();
    // evol1.print_population();

    // evol1.check_and_repair_max_weight(0);
    // printf("-----------------------------\n");
    // evol1.print_population();

    // ** test pick_best_members_as_parents **

    // int best_member_ids[] = evol1.pick_best_members_as_parents();
    // int nums = 2;
    // int best_member_ids[nums];

    // evol1.pick_best_members_as_parents(best_member_ids);
    // printf("best_member_ids: %d\n", best_member_ids[0]);
    // printf("best_member_ids: %d\n", best_member_ids[1]);

    // ** test do_crossover **
    // int nums = 2;
    // int best_member_ids[nums];

    // evol1.pick_best_members_as_parents(best_member_ids);
    // printf("best_member_ids: %d\n", best_member_ids[0]);
    // printf("best_member_ids: %d\n", best_member_ids[1]);
    
    // evol1.do_crossover(best_member_ids[0], best_member_ids[1]);
    // evol1.print_population();    

    // ** test pick_best_u_individuals **
    // int u = 4;
    // double best_u_member_prices[u];
    // evol1.pick_best_u_individuals(best_u_member_prices, u);
    
    // printf("--------------------------------------\n");

    // int i;
    // int num = 6;
    // for (i = 0; i < num; i++) {
    //     printf("member %d - price= %f\n", i, evol1.compute_price(i));
    // }
    

    // // int i;
    // printf("-----------------------------------\n");
    // printf("best members: \n");
    // for (i = 0; i < u; i++) {
    //     printf("best member %d - price = %f\n", i, best_u_member_prices[i]);
    // }
    // printf("\n");

    // ** test2 pick_best_u_individuals **
    // int i;
    // printf("prices of members: \n");
    // for (i = 0; i < 6; i++) {
    //     printf("member id = %d - price = %f\n", i, evol1.compute_price(i));
    // }

    // int u = 4;
    // int best_u_member_ids[u];
    // evol1.pick_best_u_individuals(best_u_member_ids, u);
    
    // printf("\n\best members of members: \n");
    // for (i = 0; i < u; i++) {
    //     printf("best member id = %d, price= %f\n", best_u_member_ids[i], 
    //             evol1.compute_price(best_u_member_ids[i]));
    // }

    // printf("\n");

    
    // ** test check_bag_limitation_and_repair **
    // int num = 9;
    // double numbers[num] = {5, 2, 0.5, 1, 7, 4, 3, 0, 6};

    // int i;
    // for (i = 0; i < num; i++) {
    //     printf("unmodified element %d = %f\n", i, numbers[i]);
    // }
    
    // printf("-----------------------------------------\n");

    // evol1.check_bag_limitation_and_repair_member(numbers);
    // for (i = 0; i < num; i++) {
    //     printf("modified element %d = %f\n", i, numbers[i]);
    // }

    // ** test2 check_bag_limitation_and_repair **
    //     double (*popul)[9] = evol1.population;

    //     int i;
    //     int nums = 6;
    //     for (i = 0; i < nums; i++) {
    //         evol1.check_bag_limitation_and_repair_member(popul[i]);
    //     }

    // printf("------------------------------\n");

    // evol1.print_population();

    // ** test3 check_bag_limitation_and_repair **
    // evol1.check_bag_limitation_and_repair_population();

    // printf("\n-----------------------------------------\n");
    // evol1.print_population();


    return 0;
}