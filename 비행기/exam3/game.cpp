#include "stdafx.h"
Player player;
extern Image* imgPlayer = NULL;
extern Image* imgEnemy = NULL;
extern Image* imgBullet = NULL;
extern Image* imgBullet2 = NULL;
extern Image* imgExplosion = NULL;
extern Rect rectScreen(0, 0, 512, 512);
extern Enemy* enemys[MAX_ENEMY] = {};
extern Bullet* bullets[MAX_BULLET] = {};
extern Explosion* explosions[MAX_EXPLOSION] = {};
double curFps;

void OnCreate(HWND hWNd) {
	plusEngine::fpOnLoop = OnLoop;
	plusEngine::fpOnRender = OnRender;
	
    imgPlayer = new Image(L"../../res/spaceship_crop.png");
	imgEnemy = new Image(L"../../res/spaceship_enemy.png");
	imgBullet = new Image(L"../../res/bullet2_crop.png");
	imgBullet2 = new Image(L"../../res/bullet2_crop2.png");
	imgExplosion = new Image(L"../../res/explosion_small.png");
	player.Setup(irr::core::vector2df(rectScreen.Width/2, rectScreen.Height - imgPlayer->GetHeight() * 2), imgPlayer);
}

int Count(Bullet** bullets, int size) {
	int count = 0;
	for (int i = 0; i < size; i++)
		count += !!bullets[i];
	return count;
}

int CreateEnemy() {
	for (int i = 0; i < MAX_ENEMY; i++) {
		if (!enemys[i]) {
			Enemy* enemy = new Enemy;
			int h = imgEnemy->GetHeight();
			irr::core::vector2df startPos(rand() % rectScreen.Width, h);
			enemy->Setup(startPos, imgEnemy);
			enemys[i] = enemy;
			return 1;
		}
	}
	return 0;
}

int CreateBullet(void* mother) {
	for (int i = 0; i < MAX_BULLET; i++) {
		if (!bullets[i]) {
			Bullet* bullet = new Bullet;
			int h = imgBullet->GetHeight();
			irr::core::vector2df startPos(rand() % rectScreen.Width, -h);
			double s = 1.0;
			irr::core::vector2df speed;
			speed = player.pos - startPos;
			speed.normalize();
			speed.rotateBy(rand() % 60 - 60 / 2.);
			speed *= s;
			bullet->Setup(mother, startPos, speed, true, NULL, imgBullet);
			bullets[i] = bullet;
			return 1;
		}
	}
	return 0;
}

int CreateBullet2(void* mother) {
	for (int i = 0; i < MAX_BULLET; i++) {
		if (!bullets[i]) {
			Bullet* bullet = new Bullet;
			int h = imgBullet->GetHeight();
			irr::core::vector2df startPos(rand() % rectScreen.Width, -h);
			double s = 0.2;
			irr::core::vector2df speed;
			speed = player.pos - startPos;
			speed.normalize();
			speed.rotateBy(rand() % 45 - 45/2.);
			speed *= s;
			bullet->Setup(mother, startPos, speed, true, &player.pos, imgBullet2);
			bullets[i] = bullet;
			return 1;
		}
	}
	return 0;
}

int CreateExplosion(irr::core::vector2df pos) {
	for (int i = 0; i < MAX_EXPLOSION; i++) {
		if (!explosions[i]) {
			Explosion* explosion = new Explosion;
			explosion->Setup(pos, 1, imgExplosion);
			explosions[i] = explosion;
			return 1;
		}
	}
	return 0;
}

void OnLoop(double fDelta) {
	// Player
	player.OnApply(fDelta);

	// Bullet
	for (int i = 0; i < MAX_BULLET; i++) {
		if (bullets[i])
			bullets[i]->OnApply(fDelta);
	}

	// Explosion
	for (int i = 0; i < MAX_EXPLOSION; i++) {
		if (explosions[i])
			explosions[i]->OnApply(fDelta);
	}

	// Generate bullet
	static double tick = 0;
	tick += fDelta;
	if (tick > 0.1) {
		tick -= 0.1;
		if (rand() % 10)
			CreateBullet(NULL);
		else
			CreateBullet2(NULL);
	}

	// Generate enemy
	static double tick_enemy = 0;
	tick_enemy += fDelta;
	if (tick_enemy > 2.0) {
		tick_enemy -= 2.0;
		CreateEnemy();
	}

	// Destroy bullets
	for (int i = 0; i < MAX_BULLET; i++) {
		if (bullets[i] && bullets[i]->destroy) {
			delete bullets[i];
			bullets[i] = NULL;
		}
	}

	// Destroy explosions
	for (int i = 0; i < MAX_EXPLOSION; i++) {
		if (explosions[i] && explosions[i]->destroy) {
			delete explosions[i];
			explosions[i] = NULL;
		}
	}

	// Destroy enemys
	for (int i = 0; i < MAX_ENEMY; i++) {
		if (enemys[i] && enemys[i]->destroy) {
			delete enemys[i];
			enemys[i] = NULL;
		}
	}
}


void OnRender(double fDelta , Graphics* grp_) {
	Graphics& grp = *grp_;
	grp.Clear(Color(60,60,60));

	// Player
	player.OnRender(&grp);

	// Enemy
	for (int i = 0; i < MAX_ENEMY; i++) {
		if (enemys[i])
			enemys[i]->OnRender(&grp);
	}

	// Bullet
	for (int i = 0; i < MAX_BULLET; i++) {
		if (bullets[i])
			bullets[i]->OnRender(&grp);
	}

	// Explosion
	for (int i = 0; i < MAX_EXPLOSION; i++) {
		if (explosions[i])
			explosions[i]->OnRender(&grp);
	}

	int n_bullets = Count(bullets, MAX_BULLET);
	Color white(255, 255, 255);
	plusEngine::printf(&grp, white, 0, 0, L"FPS: %f", curFps);
	plusEngine::printf(&grp, white, 0, 25, L"Bullets: %d", n_bullets);
	plusEngine::printf(&grp, white, 0, 50, L"Score: %d", player.score);
	plusEngine::printf(&grp, white, 0, 75, L"Life: %d", player.life);
}

void OnDestroy() {
	//delete imgPlayer;
}