

#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

const int ITERATIONS = 100;

struct subNode {
    short handValue;
    double weight;
    
    int nActions;
    double ev[10];
    double frequencies[10];
};

struct node {
    int currentPot;
    short playerPosition;
    // storing actions
    int nActions;
    int actions[5];
    
    // sub nodes
    int nSubnodes;
    struct subNode subNodes[50];
    
    // next nodes
    int nNextNodes;
    struct node* nextNodes[5];
    
};



int main()
{
    printf("Starting\n");
    
    const int heroHands[4] = { 5, 11, 12, 13 };
    const int vilainHands[4] = { 6, 7, 8, 9 };
    
    // making tree
    
    
    // root
    
    struct node root = { .currentPot = 100, .playerPosition = -1, .nActions = 2, .nSubnodes = 4 };
    root.actions[0] = -1;
    root.actions[1] = 25;
    
    for (int i=0; i<4; i++)
    {
        struct subNode s = { .handValue = heroHands[i], .weight = 1.0, .nActions = 2 };
        root.subNodes[i] = s;
    }
    
    // level 2
    
    struct node afterCheck = { .currentPot = 100, .playerPosition = 1, .nActions = 1 };
    struct node afterBet = { .currentPot = 125, .playerPosition = 1, .nActions = 2 };
    
    afterCheck.actions[0] = 0; // only check back possible
    
    afterBet.actions[0] = -3; // fold
    afterBet.actions[1] = -2; // call
    
    for (int i=0; i<4; i++)
    {
        struct subNode s1 = { .handValue = vilainHands[i], .weight = 1.0, .nActions = 1 };
        afterCheck.subNodes[i] = s1;
        
        struct subNode s2 = { .handValue = vilainHands[i], .weight = 1.0, .nActions = 2 };
        afterBet.subNodes[i] = s2;
    }
    
    root.nNextNodes = 2;
    root.nextNodes[0] = &afterCheck;
    root.nextNodes[1] = &afterBet;
    
    
    // Iterate
    
    for (int j=0; j<ITERATIONS; j++)
    {
        struct Queue* nodeQueue = newQueue(15);
        enqueue(&nodeQueue, &root);
        
        struct node baseNode = &root;
        
        while (nodeQueue.size > 0)
        {
            // add next nodes
            
            
        }
        
        freeQueue(nodeQueue);
        
    }
    
    
    
    
    
    
    
    
    return 0;
}
