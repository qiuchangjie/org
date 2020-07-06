# Lua编码规范

## 文件格式

统一使用UTF-8无BOM的文件格式。

## 术语定义

**Pascal 大小写**

将标识符的首字母和后面连接的每个单词的首字母都大写。可以对三字符或更多字符的标识符使用Pascal 大小写。例：

`BackColor`

**小驼峰**
标识符的首字母小写，而每个后面连接的单词的首字母都大写。例：

`backColor`

## 代码外观

### 列宽

代码列宽控制在120字符左右。

### 行数

* 单个函数行数控制在100以内。
* 单个类的行数控制在4000以内。

### 换行

当表达式超出或即将超出规定的列宽，遵循以下规则进行换行

- 在逗号后换行。
- 在操作符前换行。
- 规则1优先于规则2。

当以上规则会导致代码混乱的时候自己采取更灵活的换行规则。

### 缩进 

缩进应该是每行一个Tab(4个空格)，不要在代码中使用Tab字符。

## 文件命名

* 基本规则：清楚表达文件的功能和用途，约定俗成的命名尽量遵守，如：Login.lua、Util.lua等。尽量使用英文表意。
* 文件后缀：lua程序文件使用.lua。

## 命名原则

* 变量名不能与关键字冲突，不仅与当前语言，同时尽量不要与其它常用语言关键字冲突。
* 变量名不能有多义性。作用域内同一变量名只能代表一个意思，尽管lua允许局部用local重名变量，但应避免这样使用。另<font color=red>严格禁止局部变量与全局变量同名</font>。
* 变量命名最主要简洁表达其意义。尽量使用比较通用易懂的英文单词，尽量避免使用拼音。尽量不使用看似通用，但并没有实际意义的名字，如：Flag、Type、Class等。
* 尽可能少用全局变量。

### 大小写规则

* 类名：Pascal，首字母大写，如：
```lua 
    local SceneObject = BaseClass("SceneObject")
```

* Table 名：Pascal，首字母大写，如：
```lua
    local GameLaunch = {}
```

* 全局变量：Pascal，首字母大写，如：
```lua
    DataManager = {}
```

* Table 的 private 成员变量：小驼峰，如：
```lua
    self.spriteName = "icon001"
```

* Table 的 public 成员变量：大驼峰，如：
```lua
    self.Name = "sword"
```

* Table 的私有方法：下划线+小驼峰，如：
```lua
    function BaseItem:_getCount() end
```

* 文件中的local方法：下划线+小驼峰，如：
```lua
    function _getSize() end
```

## 特殊前缀
Lua中如果引用了Unity侧原生组件，需要添加前缀unity，如：
```lua
self.unityImage = UIUtil.FindImage(self.transform)
self.unityRawImage = UIUtil.FindRawImage(self.transform)
self.unityButton = UIUtil.FindButton(self.transform)
```

## 其它注意事项

* 尽量不能直接操作其它模块或对象的成员变量，尽量使用接口。
* <font color=red>代码提交时注意检查是否有临时打印的语句，需要删掉</font>。
* 临时打印调试信息时，不能只打印关注的值，必须加上一些固定的描述，如：print(Name) 要改成 print(“TestName---“,Name)。后者容易根据打印内容搜索到代码。
* 确定无用的被注释代码，请删除
