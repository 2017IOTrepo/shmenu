## CP4 基本模块化设计

### 开闭原则

- 开放扩展，封闭修改。
- 设计模式（复用pattern）
- 模块复用和系统复用
- 业务逻辑层和数据存储层
- 抽象实际上是选择性地忽略一些细节

## CP5 

- 参数化上下文
- 生死相依原则(create delete同时出现)

### 接口分类

- 共享数据或变量名
- call-in functions
- callback functions
- 同步调用接口
- 异步调用接口
  - 信号量、消息队列等方式实现

![image-20200829183638187](https://cdn.jsdelivr.net/gh/xmmmmmovo/ResourcesBackup/blog/pics/20200829183645.png)

### 接口设计

不要太具体，也不要太一般(通用)