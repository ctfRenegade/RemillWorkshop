#include <stdint.h>

typedef struct {
  float x;
  float y;
  float z;
} Vec3;

typedef struct {
  uint32_t speed;
  Vec3 direction;
} Bullet;

typedef struct {
  uint32_t id;
  char name[256];
  Vec3 position;
  Vec3 viewangle;
  Bullet bullet;
} Player;

uint32_t exercise0_GetIndex(uint64_t some_array[], uint64_t index) {
  uint64_t value = some_array[index];
  return (uint32_t)value;
}

uint32_t exercise1_GetPlayerId(Player *player) {
  uint32_t player_id = player->id;
  return player_id;
}

char *exercise2_GetPlayerName(Player *player) {
  char *player_name = player->name;
  return player_name;
}

Vec3 *exercise3_GetPlayerPosition(Player *player) {
  Vec3 *player_pos = &player->position;
  return player_pos;
}

float exercise4_GetPlayersomesome(Player *player) {
  Vec3 *player_pos = exercise3_GetPlayerPosition(player);
  float x_pos = player_pos->x;
  Vec3 *direction = &player->viewangle;
  float x_dir = direction->x;
  float sum = x_pos + x_dir;

  return sum;
}

float exercise5_GetotherPos(Player player[]) {
  float otherbullet = player[3].bullet.direction.z;
  return otherbullet;
}

int main() {
}
