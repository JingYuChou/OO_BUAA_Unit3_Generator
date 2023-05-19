#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM 20
#define NUM_Person 300
#define NUM_Group 300
#define NUM_Message 30
#define probability 15

char cmd[40][5] = {{"ap"},//add_person id name age
                   {"ar"},//add_relation id id value
                   {"qv"},//query_value id id
                   {"qci"},//query_circle id id
                   {"qbs"},//query_block_sum
                   {"qts"},//query_triple_sum
                   {"ag"},//add_group id
                   {"atg"},//add_to_group id1 id2
                   {"dfg"},//del_from_group id1 id2
                   {"qgvs"},//query_group_value_sum id
                   {"qgav"},//query_group_age_var id
                   {"mr"},//modify_relation id1 id2 value
                   {"qba"},//query_best_acquaintance id
                   {"qcs"},//qiery_couple_sum
                   {"am"},//add_message id socialValue type id1 personid|groupid
                   {"sm"},//send_message id
                   {"qsv"},//query_social_value id
                   {"qrm"}//query_received_messages id
};

char cmd1[100][5] = {{"ap"},//add_person id name age
                     {"ar"},//add_relation id id value
                     {"ar"},//add_relation id id value
                     {"ar"},//add_relation id id value
                     {"ar"},//add_relation id id value
                     {"ar"},//add_relation id id value
                     {"ar"},//add_relation id id value
                     {"ar"},//add_relation id id value
                     {"ar"},//add_relation id id value
                     {"ar"},//add_relation id id value
                     {"ar"},//add_relation id id value
                     {"ar"},//add_relation id id value
                     {"ar"},//add_relation id id value
                     {"qv"},//query_value id id
                     {"qv"},//query_value id id
                     {"qv"},//query_value id id
                     {"qci"},//query_circle id id
                     {"qci"},//query_circle id id
                     {"qci"},//query_circle id id
                     {"qbs"},//query_block_sum
                     {"qbs"},//query_block_sum
                     {"qbs"},//query_block_sum
                     {"qts"},//query_triple_sum
                     {"qts"},//query_triple_sum
                     {"qts"},//query_triple_sum
                     {"ag"},//add_group id
                     {"ag"},//add_group id
                     {"atg"},//add_to_group id1 id2
                     {"atg"},//add_to_group id1 id2
                     {"atg"},//add_to_group id1 id2
                     {"atg"},//add_to_group id1 id2
                     {"atg"},//add_to_group id1 id2
                     {"dfg"},//del_from_group id1 id2
                     {"dfg"},//del_from_group id1 id2
                     {"dfg"},//del_from_group id1 id2
                     {"dfg"},//del_from_group id1 id2
                     {"qgvs"},//query_group_value_sum id
                     {"qgvs"},//query_group_value_sum id
                     {"qgvs"},//query_group_value_sum id
                     {"qgav"},//query_group_age_var id
                     {"qgav"},//query_group_age_var id
                     {"qgav"},//query_group_age_var id
                     {"mr"},//modify_relation id1 id2 value
                     {"mr"},//modify_relation id1 id2 value
                     {"mr"},//modify_relation id1 id2 value
                     {"mr"},//modify_relation id1 id2 value
                     {"mr"},//modify_relation id1 id2 value
                     {"qba"},//query_best_acquaintance id
                     {"qba"},//query_best_acquaintance id
                     {"qba"},//query_best_acquaintance id
                     {"qba"},//query_best_acquaintance id
                     {"qcs"},//qiery_couple_sum
                     {"qcs"},//qiery_couple_sum
                     {"qcs"},//qiery_couple_sum
                     {"qcs"},//qiery_couple_sum
                     {"am"},//add_message id socialValue type id1 personid|groupid
                     {"am"},//add_message id socialValue type id1 personid|groupid
                     {"am"},//add_message id socialValue type id1 personid|groupid
                     {"sm"},//send_message id
                     {"qsv"},//query_social_value id
                     {"qsv"},//query_social_value id
                     {"qsv"},//query_social_value id
                     {"qrm"},//query_received_messages id
                     {"qrm"},//query_received_messages id
                     {"qrm"}
};
int num_person, num_group, num_message, group_len[500], groupPerson[500][1111];
int hash[5000][5000];

int RandPerson() {
    if (num_person > 0)
        return rand() % num_person + 1;
    else
        return 5;
}

int RandGroup() {
    if (num_group > 0)
        return rand() % num_group + 1;
    else
        return 5;
}

int RandMessage() {
    if (num_message > 0)
        return rand() % num_message + 1;
    else
        return 5;
}

int RandPersonInGroup(int id) {
    if (group_len[id - 1] > 0)
        return groupPerson[id - 1][rand() % group_len[id - 1]];
    else
        return RandPerson();
}

int Exception() {
    return rand() % probability;
}

void AddPerson(FILE *file) {
    if (Exception() > 1 && num_person < NUM_Person) {
        fprintf(file, "ap %d %d %d\n", ++num_person, num_person, rand() % 200);
    } else {
        fprintf(file, "ap %d %d %d\n", RandPerson(), RandPerson(), rand() % 200);
    }
}

void AddRelation(FILE *file) {
    fprintf(file, "ar %d %d %d\n", RandPerson(), RandPerson(), rand() % 50 + 1);
}

void Queryvalue(FILE *file) {
    fprintf(file, "qv %d %d\n", RandPerson(), RandPerson());
}

void QueryBlockSum(FILE *file) {
    fprintf(file, "qbs\n");
}

void QueryTripleSum(FILE *file) {
    fprintf(file, "qts\n");
}

void AddGroup(FILE *file) {
    if (Exception() > 0 && num_group < NUM_Group) {
        fprintf(file, "ag %d\n", ++num_group);
    } else {
        fprintf(file, "ag %d\n", RandGroup());
    }
}

void AddToGroup(FILE *file) {
    int group = RandGroup();
    if (Exception() > 0) {
        if (Exception() > 0) {
            int person = RandPerson();
            fprintf(file, "atg %d %d\n", person, group);
            if (hash[group - 1][person - 1] == 0) {
                groupPerson[group - 1][group_len[group - 1]++] = person;
                hash[group - 1][person - 1]++;
            }
        } else {
            fprintf(file, "atg %d %d\n", num_person + 1, group);//person超了
        }
    } else {
        fprintf(file, "atg %d %d\n", RandPerson(), num_group + 1);//groupid超了
    }
}

void DelFromGroup(FILE *file) {
    if (Exception() > 0) {
        int group = RandGroup();
        fprintf(file, "dfg %d %d\n", RandPersonInGroup(group), group);
    } else
        fprintf(file, "dfg %d %d\n", RandPerson(), RandGroup() + 5);
}

void QueryGroupValueSum(FILE *file) {
    if (Exception() > 1) {
        fprintf(file, "qgvs %d\n", RandGroup());
    } else
        fprintf(file, "qgvs %d\n", num_group + 1);
}

void QueryGroupAgeVar(FILE *file) {
    if (Exception() > 0) {
        fprintf(file, "qgav %d\n", RandGroup());
    } else
        fprintf(file, "qgav %d\n", num_group + 1);
}

void ModifyRelation(FILE *file) {
    fprintf(file, "mr %d %d %d\n", RandPerson(), RandPerson(), rand() % 100 - 50);
}

void QueryBestAcquaintance(FILE *file) {
    fprintf(file, "qba %d\n", RandPerson());
}

void QueryCoupleSum(FILE *file) {
    fprintf(file, "qcs\n");
}

void AddMessage(FILE *file) {
    int person1, type, group, person2;
    person1 = RandPerson();
    int socialValue = rand() % 20;
    type = rand() % 2;
    if (type == 1) {
        group = RandGroup();
        fprintf(file, "am %d %d %d %d %d\n", ++num_message, socialValue, 1, person1, group);
    } else {
        person2 = RandPerson();
        fprintf(file, "am %d %d %d %d %d\n", ++num_message, socialValue, 0, person1, person2);
    }
}

void QuerySocialValue(FILE *file) {
    if (Exception() > 0) {
        fprintf(file, "qsv %d\n", RandPerson());
    } else
        fprintf(file, "qsv %d\n", num_person + 1);
}

void QueryReceivedMessages(FILE *file) {
    fprintf(file, "qrm %d\n", RandPerson());
}

void SendMessage(FILE *file) {
    fprintf(file, "sm %d\n", RandMessage());
}

void QueryCircle(FILE *file) {
    fprintf(file, "qci %d %d\n", RandPerson(), RandPerson());
}

int selction(char str[]) {
    for (int i = 0; i < 18; i++) {
        if (strcmp(str, cmd[i]) == 0)
            return i;
    }
}

void generator(FILE *file) {
    int index = rand() % 64;
    switch (selction(cmd1[index])) {
        case 0:
            AddPerson(file);
            break;
        case 1:
            AddRelation(file);
            break;
        case 2:
            Queryvalue(file);
        case 3:
            QueryCircle(file);
        case 4:
            QueryBlockSum(file);
            break;
        case 5:
            QueryTripleSum(file);
            break;
        case 6:
            AddGroup(file);
            break;
        case 7:
            AddToGroup(file);
            break;
        case 8:
            DelFromGroup(file);
            break;
        case 9:
            QueryGroupValueSum(file);
            break;
        case 10:
            QueryGroupAgeVar(file);
            break;
        case 11:
            ModifyRelation(file);
            break;
        case 12:
            QueryBestAcquaintance(file);
            break;
        case 13:
            QueryCoupleSum(file);
            break;
        case 14:
            AddMessage(file);
            break;
        case 15:
            SendMessage(file);
            break;
        case 16:
            QuerySocialValue(file);
            break;
        case 17:
            QueryReceivedMessages(file);
            break;
    }
}

int main() {
    int num = 10500;
    while (num-- > 10000) {
        printf("%d\n", num);
        num_person = num_message = num_group = 0;
        char filename[100];
        memset(filename, 0, 100);
        memset(group_len, 0, 500 * sizeof(int));
        memset(groupPerson, 0, 500 * 1111 * sizeof(int));
        memset(hash, 0, 5000 * 5000 * sizeof(int));
        char nums[100];
        strcat(filename, "hw10datas\\fileIn");
        itoa(num, nums, 10);
        strcat(filename, nums);
        strcat(filename, ".txt");
        FILE *out = fopen(filename, "w");
        for (int i = 0; i < 10; i++) {
            AddPerson(out);
        }
        for (int i = 0; i < 950; i++) {
            generator(out);
        }
    }
    return 0;
}
