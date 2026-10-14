# GoldenSunTheBrokenSealRecomp

[English](README.md) | [简体中文](README.zh-CN.md)

基于 [GBARecomp](https://github.com/mstan/gbarecomp) 与 [recomp-ui](https://github.com/mstan/recomp-ui) 构建的《黄金太阳：开启的封印》（GBA，美版/欧版，游戏代号：AGSE，Maker：01，Rev 0）Windows x64 原生静态重编译版本。

> **v0.1.0-preview — 实验性预览版本**  
> 本项目为非商业性质的开源研究与爱好者复原项目，与任天堂（Nintendo）或 Camelot Software Planning 没有任何关联、赞助或背书关系。运行本作需要玩家自行提供合法提取的 GBA ROM 与零售版 GBA BIOS 文件。未声称全主线通关与全部隐藏迷宫已完全验证。

《黄金太阳：开启的封印》（*Golden Sun: The Broken Seal*）是 Camelot 与任天堂在 Game Boy Advance 平台推出的经典奇幻 RPG 杰作。本项目将原版卡带的 ARM/Thumb 指令静态转译为 Windows 原生 x64 指令，不仅保留了原汁原味的游戏物理、战斗动画、伪 3D Mode-7 镜头调度与精灵/精神力系统，还集成了现代化的桌面玩家启动器。

---

## 已验证运行范围与当前状态

* [x] **BIOS / 冷启动流程**：完整支持 LLE BIOS 复位逻辑、任天堂官方动画与 Camelot 3D 公司 Logo 动画（`gba_bios.bin`）。
* [x] **标题画面与神殿主菜单**：标题动画（“PRESS START”）、存档管理菜单（`Continue`、`New Game`、`Erase`、`Copy`、`Battle`）与槽位初始化。
* [x] **新游戏与角色起名界面**：起名界面（`Isaac` / 罗宾）、变宽字体渲染与 PPU 调色板平滑过渡。
* [x] **开篇暴风雨序章**：罗宾家、多拉与凯尔剧情动画、室外暴风雨与闪电特效、阿尔法山巨石滚落事件以及海夫村下层河岸全流程。
* [x] **首场战斗与回合制引擎**：海夫村伪 Mode-7 暴风雨战斗场景（`野菇 x2`）、队伍与角色指令轮盘（`攻击`、`精神力`、`物品`、`防御`）及战斗回合结算。
* [x] **卡带 Flash512 存档机制**：Macronix `MX29L512` 64 KB Flash 芯片协议（`0x1CC2`，`FLASH_V123`），支持原始扇区擦除与写入校验，与磁盘文件（`saves/gs1.sav` 以及旧版 `gs1.sav`）无损双向持久化。
* [x] **原生玩家启动器（recomp-ui）**：内置基于 Dear ImGui 的交互式图形启动界面，支持 ROM/BIOS 浏览选择、SHA-1 校验、按键映射、画面缩放与音频音量调节。
* [x] **Windows GUI 子系统集成**：采用原生 WinMain 子系统（`-mwindows`），双击 EXE 绝不弹出黑色的 CMD 命令行控制台。

### 开放社区测试范围

本预览版本重点提供稳定可靠的原生运行底座。以下内容仍需社区共同验证：
* 维亚德（Weyard）大陆后续章节：阿尔法山索尔神殿、水之灯塔、科利马森林、巴比灯塔、金星灯塔等主线剧情。
* 高阶召唤兽动画（审判、陨石、托尔等）、高阶精神力特效与复杂多目标法术脚本。
* 神殿主菜单中的对战竞技场模式及联机通信。
* 长时间运行下各城镇与迷宫 MP2K 音频混音表现。

---

## 玩家快速上手

玩家无需安装任何开发工具（如 CMake、Ninja、GCC 或 Python）。

1. **下载**：从本仓库 Releases 页面下载 `GoldenSunTheBrokenSealRecomp-windows-x64-v0.1.0-preview.zip`。
2. **解压**：解压压缩包内所有文件至任意非中文可写目录，确保主程序 `GoldenSunTheBrokenSealRecomp.exe`、DLL 动态链接库（`SDL2.dll` 等）、`assets/` 资源目录、`game.toml` 及 `licenses/` 处于同级。
3. **运行**：双击运行 `GoldenSunTheBrokenSealRecomp.exe`。
4. **启动器配置**：
   * 点击 **Browse** 分别选择你持有的正版 ROM 文件（`.gba`）与 GBA 零售版 BIOS（`.bin`）。
   * 启动器将自动校验文件大小与 SHA-1 哈希值。验证通过后将显示绿色对勾。
   * 根据偏好设置手柄按键、键盘映射、窗口倍率与音量。
5. **开始游戏**：点击 **Play** 即可进入游戏！

> [!TIP]
> 选定的路径和配置将自动保存在同级目录下的 `rom.cfg`、`bios.cfg`、`config.ini` 与 `keybinds.ini` 中。若勾选了“跳过启动器（Skip Launcher）”，日后可通过桌面快捷方式或命令行附加 `--launcher` 参数重新唤出启动配置面板。

---

## 必须自备的文件

基于版权保护合规要求，本项目及发布包中**严禁且绝不包含**任何受版权保护的原始游戏 ROM 数据或任天堂 BIOS。

| 文件 | 适用版本 | 规定文件大小 | SHA-1 哈希值 | CRC-32 |
|---|---|---:|---|---|
| **游戏 ROM** | 《黄金太阳：开启的封印》（美版/欧版，代码 `AGSE`，Maker `01`） | 8,388,608 字节 | `5c4695205413df7db52b9a184815a07783999971` | `6DAEBFBB` |
| **GBA BIOS** | 零售版 Game Boy Advance BIOS | 16,384 字节 | `300c20df6731a33952ded8c436f7f186d25d3492` | — |

> [!WARNING]
> 日版 ROM、修改版 ROM 或非官方 HLE BIOS 将被启动器严格拦截并拒绝载入。修改文件名无法绕过哈希检验。

---

## 按键操作与画面设置

### 默认键盘按键

| GBA 按键 | PC 默认按键 | 功能说明 |
|---|---|---|
| **方向键** | `W / A / S / D` 或 `↑ / ↓ / ← / →` | 移动 / 菜单选择 |
| **A 键** | `Z` / `J` | 确认 / 对话 / 调查 |
| **B 键** | `X` / `K` | 取消 / 奔跑（按住移动） |
| **L 键** | `Q` / `U` | 精神力快捷键 L / 菜单翻页 |
| **R 键** | `E` / `I` | 精神力快捷键 R / 菜单翻页 |
| **START** | `Enter` | 主菜单（状态、精神力、精灵、物品） |
| **SELECT** | `Backspace` / `Tab` | 地图 / 辅助功能 |

### 游戏手柄支持

支持 Xbox（XInput）、PlayStation DualShock 4 / DualSense、Nintendo Switch Pro Controller 及通用 DirectInput 手柄，即插即用。玩家可在启动器 **Input** 面板自由自定义键位。

### 画面与声音

* **窗口比例**：支持 1x 至 6x 整数倍缩放，以及无边框全屏模式（快捷键 `F11` / `Alt+Enter`）。
* **画面纵横比**：原生 3:2（240 × 160 渲染），像素锐利。
* **音频**：主音量滑块控制，16 位 44.1 kHz 双声道立体声输出。

---

## 存档与配置存储

* **卡带存档路径**：通过启动器或直接运行启动时，存档默认保存在同级目录下的 **`saves/gs1.sav`**。
* **向前兼容**：若检测到同级目录下已存在先前的旧版 `gs1.sav`，程序将自动继承并继续使用，绝不删除或覆盖玩家已有数据。
* **硬件仿真度**：精确模拟 Macronix `MX29L512` 64 KB Flash 芯片（`0x1CC2`，`FLASH_V123`），生成的存档与实机卡带及常见 GBA 模拟器完全互通。

---

## 源码构建（开发者向）

### 环境需求

* 64 位 Windows 10 / 11
* MinGW-w64（GCC 11+，支持 C++20）
* CMake 3.20+ 与 Ninja
* SDL2 MinGW 开发库（`x86_64-w64-mingw32`）
* Git

### 构建步骤

```powershell
# 1. 克隆代码仓库
git clone https://github.com/Zaxaerith/GoldenSunTheBrokenSealRecomp.git
cd GoldenSunTheBrokenSealRecomp

# 2. 一键编译
.\build.ps1
```

编译生成：
* 游戏主程序：`build\host\GoldenSunTheBrokenSealRecomp.exe`
* 启动器门禁测试：`build\host\launcher_contract.exe`

---

## 许可证与致谢

* **GBARecomp**：由 Matthew Stanley 开发（[mstan/gbarecomp](https://github.com/mstan/gbarecomp)）。采用 [PolyForm Noncommercial 1.0.0](https://polyformproject.org/licenses/noncommercial/1.0.0/) 许可证。
* **recomp-ui**：由 Matthew Stanley 开发（[mstan/recomp-ui](https://github.com/mstan/recomp-ui)）。采用 MIT 许可证。
* **GoldenSunTheBrokenSealRecomp 适配代码**：由 Zaxaerith 整合适配，采用 [PolyForm Noncommercial License 1.0.0](LICENSE) 许可证。
* **第三方组件**：
  * Dear ImGui — MIT License
  * toml++ — MIT License
  * SDL2 — zlib License
  * arm-recomp-core — MIT License
  * mGBA BIOS HLE 降级源码 — MPL-2.0（见 `licenses/mpl-source/`）
  * 开源字体库（LatoLatin、OpenMoji、NotoSansSymbols2）— OFL-1.1 / CC BY-SA 4.0

详见 [THIRD_PARTY_NOTICES.md](THIRD_PARTY_NOTICES.md)。

---

## 免责声明

*Golden Sun*（《黄金太阳》）及相关角色、美术资产和注册商标归 **任天堂株式会社（Nintendo Co., Ltd.）** 与 **Camelot Software Planning** 所有。

本项目为独立的非商业技术研究项目，不附属于任天堂或 Camelot，亦未获得其官方授权。仓库及发行包内严禁且未分发任何受版权保护的游戏 ROM、BIOS 或美术资产。
