#pragma once

/*

Base class used for all games, all games must inherit from this

*/

#include <QtGui/QPainter>
#include <memory>
#include <functional>
#include <vector>
#include <string>
#include "entity.h"
#include "randgen.h"
#include "resources.h"
#include "object-ids.h"
#include "game-registry.h"
#include "buffer.h"
#include "context/bigfish-context-option.h"
#include "context/bossfight-context-option.h"
#include "context/caveflyer-context-option.h"
#include "context/chaser-context-option.h"
#include "context/climber-context-option.h"
#include "context/coinrun-context-option.h"
#include "context/dodgeball-context-option.h"
#include "context/fruitbot-context-option.h"
#include "context/heist-context-option.h"
#include "context/jumper-context-option.h"
#include "context/leaper-context-option.h"
#include "context/maze-context-option.h"
#include "context/miner-context-option.h"
#include "context/ninja-context-option.h"
#include "context/plunder-context-option.h"
#include "context/starpilot-context-option.h"

// We want all games to have same observation space. So all these
// constants here related to observation space are constants forever.
const int RES_W = 64;
const int RES_H = 64;

const int RENDER_RES = 512;

void bgr32_to_rgb888(void *dst_rgb888, void *src_bgr32, int w, int h);

class VecOptions;

enum DistributionMode {
    EasyMode = 0,
    HardMode = 1,
    ExtremeMode = 2,
    MemoryMode = 10,
};

struct StepData {
    float reward = 0.0f;
    bool done = false;
    bool level_complete = false;
};

struct GameOptions {
    bool paint_vel_info = false;
    bool use_generated_assets = false;
    bool use_monochrome_assets = false;
    bool restrict_themes = false;
    bool use_backgrounds = true;
    bool center_agent = false;
    int debug_mode = 0;
    DistributionMode distribution_mode = HardMode;
    bool use_sequential_levels = false;

    // coinrun_old
    bool use_easy_jump = false;
    int plain_assets = 0;
    int physics_mode = 0;
};

class Game {
  public:
    const std::string game_name;
    std::map<std::string, int> info_name_to_offset;

    GameOptions options;

    bool initial_reset_complete = false;
    bool grid_step = false;
    int level_seed_low = 0;
    int level_seed_high = 1;
    int game_type = 0;
    int game_n = 0;

    RandGen level_seed_rand_gen;
    RandGen rand_gen;

    StepData step_data;
    int action = 0;

    int timeout = 0;

    int current_level_seed = 0;
    int prev_level_seed = 0;
    int episodes_remaining = 0;
    bool episode_done = false;

    int last_reward_timer = 0;
    float last_reward = 0.0f;
    int default_action = 0;

    int fixed_asset_seed = 0;

    uint32_t render_buf[RES_W * RES_H];

    int cur_time = 0;

    bool is_waiting_for_step = false;

    // pointers to buffers
    int32_t *action_ptr;
    std::vector<void *> obs_bufs;
    std::vector<void *> info_bufs;
    float *reward_ptr = nullptr;
    uint8_t *first_ptr = nullptr;
    libenv_options e_context;

    Game(std::string name);
    void step();
    void reset();
    void render_to_buf(void *buf, int w, int h, bool antialias);
    void parse_options(std::string name, VecOptions opt_vec);
    void parse_context_options(std::string name, VecOptions opt_vec, bool init_e_context=true);

    virtual ~Game() = 0;
    virtual void observe();
    virtual void game_init() = 0;
    virtual void game_reset() = 0;
    virtual void game_step() = 0;
    virtual void game_draw(QPainter &p, const QRect &rect) = 0;
    virtual void serialize(WriteBuffer *b);
    virtual void deserialize(ReadBuffer *b);

    void *assigned_context_option = nullptr;
    BigfishContextOption *bigfish_context_option = nullptr;
    BossfightContextOption *bossfight_context_option = nullptr;
    CaveflyerContextOption *caveflyer_context_option = nullptr;
    ChaserContextOption *chaser_context_option = nullptr;
    ClimberContextOption *climber_context_option = nullptr;
    CoinrunContextOption *coinrun_context_option = nullptr;
    DodgeballContextOption *dodgeball_context_option = nullptr;
    FruitbotContextOption *fruitbot_context_option = nullptr;
    HeistContextOption *heist_context_option = nullptr;
    JumperContextOption *jumper_context_option = nullptr;
    LeaperContextOption *leaper_context_option = nullptr;
    MazeContextOption *maze_context_option = nullptr;
    MinerContextOption *miner_context_option = nullptr;
    NinjaContextOption *ninja_context_option = nullptr;
    PlunderContextOption *plunder_context_option = nullptr;
    StarpilotContextOption *starpilot_context_option = nullptr;

  private:
    int reset_count = 0;
    float total_reward = 0.0f;
};
