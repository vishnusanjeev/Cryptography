#include <stdio.h>

#define BLOCK_SIZE 1024
#define LANE_COUNT 25
#define CAPACITY_BITS 512

int main() {
    int lanes[LANE_COUNT] = {0};  
    int message_block[LANE_COUNT] = {1};  

    int zero_lanes = CAPACITY_BITS / (BLOCK_SIZE / LANE_COUNT); 
    
    for (int i = 0; i < LANE_COUNT; i++) {
        if (message_block[i] != 0 && i < zero_lanes) {
            printf("Lane %d is now non-zero.\n", i);
        }
    }
    
    return 0;
}
