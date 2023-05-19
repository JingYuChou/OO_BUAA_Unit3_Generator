#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define NUM 20
#define NUM_Person 300
#define NUM_Group 300
#define NUM_Message 30
#define probability 15
const unsigned char allChar[63] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

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
                   {"qrm"},//query_received_messages id
                   {"arem"},//add_red_envelope_message
                   {"anm"},//add_notice_message
                   {"cn"},//clean_notices
                   {"aem"},//add_emoji_message
                   {"sei"},//store_emoji_id
                   {"qp"},//query_popilarity
                   {"dce"},//delete_cold_emoji
                   {"qm"},//query_money
                   {"qlm"}//query_least_moment
};

char cmd1[1000][5] = {
        {"ap"},//add_person id name age
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
        {"qrm"},
        {"arem"},
        {"anm"},
        {"cn"},
        {"aem"},
        {"sei"},
        {"qp"},
        {"dce"},
        {"qm"},
        {"qlm"},
        {"arem"},
        {"anm"},
        {"cn"},
        {"aem"},
        {"sei"},
        {"qp"},
        {"dce"},
        {"qm"},
        {"qlm"},
        {"arem"},
        {"anm"},
        {"cn"},
        {"aem"},
        {"sei"},
        {"qp"},
        {"dce"},
        {"qm"},
        {"qlm"},
        {"arem"},
        {"anm"},
        {"cn"},
        {"aem"},
        {"sei"},
        {"qp"},
        {"dce"},
        {"qm"},
        {"qlm"},
        {"arem"},
        {"anm"},
        {"cn"},
        {"aem"},
        {"sei"},
        {"qp"},
        {"dce"},
        {"qm"},
        {"qlm"},
        {"qlm"},
        {"arem"},
        {"anm"},
        {"cn"},
        {"aem"},
        {"sei"},
        {"qp"},
        {"dce"},
        {"qm"},
        {"qlm"},
        {"qlm"},
        {"arem"},
        {"anm"},
        {"cn"},
        {"aem"},
        {"sei"},
        {"qp"},
        {"dce"},
        {"qm"},
        {"qlm"},
        {"qlm"},
        {"arem"},
        {"anm"},
        {"cn"},
        {"aem"},
        {"sei"},
        {"qp"},
        {"dce"},
        {"qm"},
        {"qlm"},
        {"qlm"},
        {"arem"},
        {"anm"},
        {"cn"},
        {"aem"},
        {"sei"},
        {"qp"},
        {"dce"},
        {"qm"},
        {"qlm"},
        {"qlm"},
        {"arem"},
        {"anm"},
        {"cn"},
        {"aem"},
        {"sei"},
        {"qp"},
        {"dce"},
        {"qm"},
        {"qlm"},
        {"qlm"},
        {"arem"},
        {"anm"},
        {"cn"},
        {"aem"},
        {"sei"},
        {"qp"},
        {"dce"},
        {"qm"},
        {"qlm"},
        {"qlm"},
        {"qlm"},
        {"qlm"},
        {"qlm"},
        {"qlm"},
        {"qlm"},
        {"qlm"},
        {"qlm"}
};
char cmd2[50][50] = {
        {"ap"},
        {"ar"},
        {"ar"},
        {"qlm"}
};
int num_person, num_group, num_message, group_len[500], groupPerson[500][1111], num_emoji, emojiList[500];
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

int RandEmoji() {
    if (num_emoji > 0)
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


void generateString(unsigned char *dest, const unsigned int len) {
    unsigned int cnt, randNo;

    for (cnt = 0; cnt < len; cnt++) {
        randNo = rand() % 62;
        *dest = allChar[randNo];
        dest++;
    }

    *dest = '\0';
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

void AddRedEnvelopeMessages(FILE *file) {
    int person1, type, group, person2;
    person1 = RandPerson();
    int socialValue = rand() % 20;
    type = rand() % 2;
    if (type == 1) {
        group = RandGroup();
        fprintf(file, "arem %d %d %d %d %d\n", ++num_message, socialValue, 1, person1, group);
    } else {
        person2 = RandPerson();
        fprintf(file, "arem %d %d %d %d %d\n", ++num_message, socialValue, 0, person1, person2);
    }
}

void AddNoticeMessages(FILE *file) {
    int person1, type, group, person2;
    person1 = RandPerson();
    int socialValue = rand() % 20 + 1;
    type = rand() % 2;
    unsigned char notice[200];
    generateString(notice, socialValue);
    if (type == 1) {
        group = RandGroup();
        fprintf(file, "anm %d %s %d %d %d\n", ++num_message, notice, 1, person1, group);
    } else {
        person2 = RandPerson();
        fprintf(file, "anm %d %s %d %d %d\n", ++num_message, notice, 0, person1, person2);
    }
}

void ClearNotice(FILE *file) {
    fprintf(file, "cn %d\n", RandPerson());
}

void AddEmojiMessage(FILE *file) {
    int person1, type, group, person2;
    person1 = RandPerson();
    type = rand() % 2;
    int flag = 1;
    int emjois[30];
    int num = 0;
    for(int i = 1;i < 20;i++) {
        if(emojiList[i] >= 0) {
            emjois[num++] = i;
        }
    }
    if(num == 0) {
        return;
    }
    int emoji = emjois[rand() % num];
    if (type == 1) {
        group = RandGroup();
        fprintf(file, "aem %d %d %d %d %d\n", ++num_message, emoji, 1, person1, group);
    } else {
        person2 = RandPerson();
        fprintf(file, "aem %d %d %d %d %d\n", ++num_message, emoji, 0, person1, person2);
    }
    if (emojiList[emoji] != -1) {
        emojiList[emoji]++;
    }
}

void StoreEmojiId(FILE *file) {
    int emoji = rand() % 20 + 1;
    fprintf(file, "sei %d\n", emoji);
    if (emojiList[emoji] == -1) {
        emojiList[emoji]++;
    }
}

void QueryPopularity(FILE *file) {
    fprintf(file, "qp %d\n", RandEmoji());
}

void DeleteColdEmoji(FILE *file) {
    int max = -1;
    for (int i = 1; i <= 20; i++) {
        if (emojiList[i] > max) {
            max = emojiList[i];
        }
    }
    if (max == -1 || max == 0) {
        fprintf(file, "dce %d\n", 114514);
    } else {
        int limit = rand() % max;
        fprintf(file, "dce %d\n", limit);
        for (int i = 1; i <= 20; i++) {
            if (emojiList[i] < limit) {
                emojiList[i] = -1;
            }
        }
    }
}

void QueryMoney(FILE *file) {
    fprintf(file, "qm %d\n", RandPerson());
}

void QueryLeastMoment(FILE *file) {
    fprintf(file, "qlm %d\n", RandPerson());
}

int selction(char str[]) {
    for (int i = 0; i < 27; i++) {
        if (strcmp(str, cmd[i]) == 0)
            return i;
    }
}

void generator(FILE *file) {
    //int index = rand() % 4;
    int index = rand() % 176;
    int n = selction(cmd1[index]);
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
        case 18:
            AddRedEnvelopeMessages(file);
            break;
        case 19:
            AddNoticeMessages(file);
            break;
        case 20:
            ClearNotice(file);
            break;
        case 21:
            AddEmojiMessage(file);
            break;
        case 22:
            StoreEmojiId(file);
            break;
        case 23:
            QueryPopularity(file);
            break;
        case 24:
            DeleteColdEmoji(file);
            break;
        case 25:
            QueryMoney(file);
            break;
        case 26:
            QueryLeastMoment(file);
            break;
    }
}

int main() {
    int num = 3000;
    while(num-- > 2500){
        printf("%d\n", num);
        num_person = num_message = num_group = num_emoji = 0;
        char filename[100];
        memset(filename, 0, 100);
        memset(group_len, 0, 500 * sizeof(int));
        memset(groupPerson, 0, 500 * 1111 * sizeof(int));
        memset(hash, 0, 5000 * 5000 * sizeof(int));
        for (int i = 0; i < 20; i++) {
            emojiList[i] = -1;
        }
        char nums[100];
        strcat(filename, "hw11datas\\fileIn");
        itoa(num, nums, 10);
        strcat(filename, nums);
        strcat(filename, ".txt");
        FILE *out = fopen(filename, "w");
        for (int i = 0; i < 10; i++) {
            AddPerson(out);
        }
        for (int i = 0; i < 9000; i++) {
            generator(out);
        }
    }
    return 0;
}
