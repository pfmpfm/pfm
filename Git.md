## Git 的命令行接口

##### 基础

```
git help <command>: 获取 git 命令的帮助信息
git init: 创建一个新的 git 仓库，其数据会存放在一个名为 .git 的目录下
git status: 显示当前的仓库状态
git add <filename>: 添加文件到暂存区
git commit: 创建一个新的提交
如何编写 良好的提交信息!
为何要 编写良好的提交信息
git log: 显示历史日志
git log --all --graph --decorate: 可视化历史记录（有向无环图）
git diff <filename>: 显示与暂存区文件的差异
git diff <revision> <filename>: 显示某个文件两个版本之间的差异
git checkout <revision>: 更新 HEAD（如果是检出分支则同时更新当前分支）
```

##### 分支和合并

```
git branch: 显示分支
git branch <name>: 创建分支
git checkout -b <name>: 创建分支并切换到该分支
相当于 git branch <name>; git checkout <name>
git merge <revision>: 合并到当前分支
git mergetool: 使用工具来处理合并冲突
git rebase: 将一系列补丁变基（rebase）为新的基线
```

##### 远端操作

```
git remote: 列出远端
git remote add <name> <url>: 添加一个远端
git push <remote> <local branch>:<remote branch>: 将对象传送至远端并更新远端引用
git branch --set-upstream-to=<remote>/<remote branch>: 创建本地和远端分支的关联关系
git fetch: 从远端获取对象/索引
git pull: 相当于 git fetch; git merge
git clone: 从远端下载仓库
```

##### 撤销

```
git commit --amend: 编辑提交的内容或信息
git reset HEAD <file>: 恢复暂存的文件
git checkout -- <file>: 丢弃修改
git restore: git2.32 版本后取代 git reset 进行许多撤销操作
```





**git log**：查看目前为止所有的存档

**git status**：可以得知，与当前存档相比，哪些文件发生了变化

**git add**：若有新的文件或已修改的文件未被跟踪，则使用此命令将文件加入跟踪列表

**git add -A**：如果需要一次添加所有未被跟踪的文件

**git commit -m "备注"**：提交修改

**git branch**：查看分支信息

**git checkout < 分支名/存档前几位哈希值>**：切换分支

**git checkout -f < 分支名/存档前几位哈希值>**：强行切换分支，丢弃未commit的修改

**git checkout -B <分支名>**：把修改结果保存到一个新的分支中, 如果分支已存在, 其内容将会被覆盖

**git diff <文件名>** ：比较同一个文件在不同分支版本中的区别（经常出现在切换至其他分支时）

**git reset --hard <存档前几位哈希值>**：强行回档（如果你读入了一个较早的存档, 那么比这个存档新的所有记录都将被删除! 这意为着你不能随便回到"将来"了）

![image-20251013165450153](C:\Users\PFM\AppData\Roaming\Typora\typora-user-images\image-20251013165450153.png)