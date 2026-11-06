#include "Enemy.h" //Gilio

Enemy::Enemy() {}

void Enemy::takeDamage(int dmg) {
  hp -= dmg;
  if (hp <= 0) {
    dead = true;
    death();
  }
}

void Enemy::death() { dead = true; }
