# FNNAS 项目 Git 操作手册

## 1. 仓库初始化与配置

### 1.1 克隆仓库

```bash
# 克隆主仓库
git clone https://github.com/ifroncy01/easepi-a2.git

# 进入项目目录
cd easepi-a2
```

### 1.2 配置 Git 信息

```bash
# 配置用户名
git config --global user.name "Your Name"

# 配置邮箱
git config --global user.email "your.email@example.com"

# 配置默认编辑器
git config --global core.editor "vim"

# 查看当前配置
git config --list
```

## 2. 分支管理

### 2.1 分支结构

本项目使用以下分支结构：

- **main**：主分支，用于发布稳定版本
- **fnnas**：FNNAS 固件相关开发分支
- **feature/**：功能开发分支
- **bugfix/**：bug 修复分支

### 2.2 分支操作

```bash
# 查看所有分支
git branch -a

# 创建新分支
git checkout -b <分支名>

# 切换分支
git checkout <分支名>

# 推送新分支到远程
git push -u origin <分支名>

# 删除本地分支
git branch -d <分支名>

# 删除远程分支
git push origin --delete <分支名>
```

## 3. 日常开发流程

### 3.1 拉取最新代码

```bash
# 拉取当前分支最新代码
git pull

# 拉取指定分支最新代码
git pull origin <分支名>
```

### 3.2 提交更改

```bash
# 查看修改状态
git status

# 添加修改到暂存区
git add .

# 提交更改
git commit -m "提交消息"

# 推送更改到远程
git push origin <分支名>
```

### 3.3 提交消息规范

提交消息应遵循以下格式：

```
<类型>: <描述>

<详细说明>（可选）
```

**类型**包括：
- `feat`：新功能
- `fix`：bug 修复
- `docs`：文档更新
- `style`：代码风格调整
- `refactor`：代码重构
- `test`：测试相关
- `chore`：构建或依赖更新

**示例**：
```
feat: 添加固件自动构建功能

- 实现 GitHub Actions 自动构建流程
- 添加构建状态检查
- 优化构建脚本
```

## 4. 远程仓库操作

### 4.1 查看远程仓库

```bash
# 查看远程仓库信息
git remote -v

# 添加远程仓库
git remote add <远程名称> <远程地址>

# 删除远程仓库
git remote remove <远程名称>

# 修改远程仓库地址
git remote set-url <远程名称> <新地址>
```

### 4.2 推送与拉取

```bash
# 推送本地分支到远程
git push origin <本地分支>:<远程分支>

# 拉取远程分支到本地
git pull origin <远程分支>:<本地分支>

# 强制推送（谨慎使用）
git push -f origin <分支名>
```

## 5. 标签管理

### 5.1 创建标签

```bash
# 创建轻量标签
git tag <标签名>

# 创建带注释的标签
git tag -a <标签名> -m "标签描述"

# 查看所有标签
git tag

# 推送标签到远程
git push origin <标签名>

# 推送所有标签到远程
git push origin --tags
```

### 5.2 删除标签

```bash
# 删除本地标签
git tag -d <标签名>

# 删除远程标签
git push origin --delete <标签名>
```

## 6. 常见问题解决

### 6.1 冲突解决

当推送时遇到冲突：

```bash
# 拉取远程代码并尝试合并
git pull origin <分支名>

# 手动编辑冲突文件
# 冲突部分会显示为：
# <<<<< HEAD
# 远程代码
# =======
# 本地代码
# >>>>>> 本地分支

# 解决冲突后提交
git add .
git commit -m "解决冲突"

# 再次推送
git push origin <分支名>
```

### 6.2 撤销更改

```bash
# 撤销工作区的修改
git checkout -- <文件>

# 撤销暂存区的修改
git reset HEAD <文件>

# 撤销最近一次提交（保留修改）
git reset HEAD~1

# 撤销最近一次提交（丢弃修改）
git reset --hard HEAD~1
```

### 6.3 清理仓库

```bash
# 清理未跟踪的文件
git clean -fd

# 清理冗余对象
git gc --aggressive --prune=now

# 清理远程已删除的分支引用
git remote prune origin
```

## 7. 工作流程最佳实践

### 7.1 开发流程

1. **从主分支创建功能分支**：
   ```bash
   git checkout main
   git pull
   git checkout -b feature/新功能
   ```

2. **进行开发并提交**：
   ```bash
   # 开发代码
   git add .
   git commit -m "feat: 新功能描述"
   ```

3. **推送到远程**：
   ```bash
   git push -u origin feature/新功能
   ```

4. **创建 Pull Request**：
   在 GitHub 上创建 PR，等待审核

5. **合并到主分支**：
   审核通过后，合并到 main 分支

### 7.2 代码审查

- 每次提交前进行自我审查
- 确保代码符合项目规范
- 编写清晰的提交消息
- 定期进行团队代码审查

## 8. 高级操作

### 8.1 变基操作

```bash
# 变基到主分支
git checkout feature/新功能
git rebase main

# 解决可能的冲突
# 完成后推送
git push -f origin feature/新功能
```

### 8.2  stash 操作

```bash
# 暂存当前修改
git stash

# 查看暂存列表
git stash list

# 恢复暂存的修改
git stash pop

# 应用特定暂存
git stash apply stash@{n}
```

### 8.3 子模块操作

如果项目包含子模块：

```bash
# 克隆包含子模块的仓库
git clone --recursive <仓库地址>

# 更新子模块
git submodule update --init --recursive

# 拉取子模块最新代码
git submodule update --remote
```

## 9. 命令速查表

| 命令 | 功能 |
|------|------|
| `git status` | 查看工作区状态 |
| `git add .` | 添加所有修改到暂存区 |
| `git commit -m "消息"` | 提交更改 |
| `git push` | 推送更改到远程 |
| `git pull` | 拉取远程更改 |
| `git checkout <分支>` | 切换分支 |
| `git branch` | 查看本地分支 |
| `git branch -a` | 查看所有分支 |
| `git merge <分支>` | 合并分支 |
| `git log` | 查看提交历史 |
| `git diff` | 查看修改内容 |

## 10. 注意事项

- **保护主分支**：main 分支应受到保护，不允许直接推送
- **定期拉取**：定期拉取远程代码，保持本地代码与远程同步
- **合理分支**：根据功能和修复创建合理的分支
- **提交规范**：遵循提交消息规范，保持提交历史清晰
- **备份重要数据**：重要操作前备份仓库，以防数据丢失

---

*文档生成时间：2026-03-20*