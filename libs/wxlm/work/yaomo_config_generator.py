"""
妖魔配置JSON文件生成器
基于pygame_gui的妖魔系统配置文件生成工具
"""

import json
import os
import tkinter as tk
from tkinter import ttk, filedialog, messagebox
from typing import Dict, List, Any, Optional


class YaomoConfigGenerator:
    """妖魔配置生成器主类"""

    def __init__(self):
        """初始化妖魔配置生成器"""
        self.root = tk.Tk()
        self.root.title("妖魔配置JSON文件生成器")
        self.root.geometry("1200x800")

        # 默认保存路径
        self.default_save_path = r"C:\mud代码\nowmud\shuiyuzhengfeng_lpc\system\yaomo\config"

        # 数据存储
        self.config_data = {}
        self.skills_list = []
        self.drops_items = []

        # 创建GUI
        self.create_gui()
        self.init_default_data()

    def create_gui(self):
        """创建GUI界面"""
        # 创建左右分栏
        main_paned = ttk.PanedWindow(self.root, orient='horizontal')
        main_paned.pack(fill='both', expand=True, padx=10, pady=10)

        # 左侧：配置文件列表
        self.create_config_list_panel(main_paned)

        # 右侧：配置编辑器
        right_frame = ttk.Frame(main_paned)
        main_paned.add(right_frame, weight=3)

        # 创建主要的notebook
        self.notebook = ttk.Notebook(right_frame)
        self.notebook.pack(fill='both', expand=True)

        # 创建两个标签页：编辑和预览
        self.create_edit_tab()
        self.create_output_tab()

        # 底部按钮区域
        self.create_bottom_buttons()

    def create_config_list_panel(self, parent):
        """创建配置文件列表面板"""
        left_frame = ttk.Frame(parent)
        parent.add(left_frame, weight=1)

        # 标题和操作按钮
        header_frame = ttk.Frame(left_frame)
        header_frame.pack(fill='x', padx=5, pady=5)

        ttk.Label(header_frame, text="现有配置列表", font=('Arial', 10, 'bold')).pack(side='left')
        ttk.Button(header_frame, text="刷新", command=self.refresh_config_list, width=8).pack(side='right', padx=2)

        # 配置列表
        list_frame = ttk.LabelFrame(left_frame, text="配置文件", padding="5")
        list_frame.pack(fill='both', expand=True, padx=5, pady=5)

        # 创建Treeview显示配置列表
        self.config_tree = ttk.Treeview(list_frame, columns=('name', 'level'), show='headings', selectmode='browse')
        self.config_tree.heading('name', text='妖魔名称')
        self.config_tree.heading('level', text='等级')
        self.config_tree.column('name', width=150)
        self.config_tree.column('level', width=60)

        # 滚动条
        config_scrollbar = ttk.Scrollbar(list_frame, orient='vertical', command=self.config_tree.yview)
        config_scrollbar.pack(side='right', fill='y')
        self.config_tree.configure(yscrollcommand=config_scrollbar.set)
        self.config_tree.pack(side='left', fill='both', expand=True)

        # 绑定双击事件
        self.config_tree.bind('<Double-Button-1>', self.on_config_double_click)

        # 操作按钮
        button_frame = ttk.Frame(left_frame)
        button_frame.pack(fill='x', padx=5, pady=5)

        ttk.Button(button_frame, text="新建配置", command=self.create_new_config).pack(side='left', padx=2, fill='x', expand=True)
        ttk.Button(button_frame, text="加载配置", command=self.load_selected_config).pack(side='left', padx=2, fill='x', expand=True)
        ttk.Button(button_frame, text="删除配置", command=self.delete_selected_config).pack(side='left', padx=2, fill='x', expand=True)

        # 初始加载配置列表
        self.refresh_config_list()

    def create_edit_tab(self):
        """创建编辑标签页（整合所有配置项）"""
        edit_frame = ttk.Frame(self.notebook)
        self.notebook.add(edit_frame, text="配置编辑")

        # 创建滚动区域
        canvas = tk.Canvas(edit_frame)
        scrollbar = ttk.Scrollbar(edit_frame, orient="vertical", command=canvas.yview)
        scrollable_frame = ttk.Frame(canvas)

        scrollable_frame.bind(
            "<Configure>",
            lambda e: canvas.configure(scrollregion=canvas.bbox("all"))
        )

        canvas.create_window((0, 0), window=scrollable_frame, anchor="nw")
        canvas.configure(yscrollcommand=scrollbar.set)

        # 在滚动区域中添加所有配置项
        self.create_basic_info_section(scrollable_frame)
        self.create_attributes_section(scrollable_frame)
        self.create_skills_section(scrollable_frame)
        self.create_drops_section(scrollable_frame)

        canvas.pack(side="left", fill="both", expand=True)
        scrollbar.pack(side="right", fill="y")

        # 绑定鼠标滚轮
        def _on_mousewheel(event):
            canvas.yview_scroll(int(-1*(event.delta/120)), "units")
        canvas.bind_all("<MouseWheel>", _on_mousewheel)

    def create_basic_info_section(self, parent):
        """创建基础信息区域"""
        basic_info_frame = ttk.LabelFrame(parent, text="基础信息", padding="10")
        basic_info_frame.pack(fill='x', padx=10, pady=10)

        # ID
        ttk.Label(basic_info_frame, text="配置ID:").grid(row=0, column=0, sticky='w', padx=5, pady=5)
        self.id_entry = ttk.Entry(basic_info_frame, width=30)
        self.id_entry.grid(row=0, column=1, padx=5, pady=5)
        ttk.Label(basic_info_frame, text="* 唯一标识符，如: yaomo_001").grid(row=0, column=2, sticky='w', padx=5, pady=5)

        # 名称
        ttk.Label(basic_info_frame, text="妖魔名称:").grid(row=1, column=0, sticky='w', padx=5, pady=5)
        self.name_entry = ttk.Entry(basic_info_frame, width=30)
        self.name_entry.grid(row=1, column=1, padx=5, pady=5)
        ttk.Label(basic_info_frame, text="* 妖魔的显示名称").grid(row=1, column=2, sticky='w', padx=5, pady=5)

        # 名称ID
        ttk.Label(basic_info_frame, text="名称ID列表:").grid(row=2, column=0, sticky='w', padx=5, pady=5)
        self.name_ids_text = tk.Text(basic_info_frame, height=2, width=40)
        self.name_ids_text.grid(row=2, column=1, padx=5, pady=5)
        ttk.Label(basic_info_frame, text="* 每行一个ID").grid(row=2, column=2, sticky='w', padx=5, pady=5)

        # 称号
        ttk.Label(basic_info_frame, text="称号:").grid(row=3, column=0, sticky='w', padx=5, pady=5)
        self.title_entry = ttk.Entry(basic_info_frame, width=30)
        self.title_entry.grid(row=3, column=1, padx=5, pady=5)
        ttk.Label(basic_info_frame, text="妖魔的称号").grid(row=3, column=2, sticky='w', padx=5, pady=5)

        # 详细描述
        ttk.Label(basic_info_frame, text="详细描述:").grid(row=4, column=0, sticky='nw', padx=5, pady=5)
        self.description_text = tk.Text(basic_info_frame, height=4, width=50)
        self.description_text.grid(row=4, column=1, columnspan=2, padx=5, pady=5)

        # 等级
        ttk.Label(basic_info_frame, text="等级:").grid(row=5, column=0, sticky='w', padx=5, pady=5)
        self.level_spinbox = ttk.Spinbox(basic_info_frame, from_=1, to=100, width=28)
        self.level_spinbox.grid(row=5, column=1, padx=5, pady=5)
        ttk.Label(basic_info_frame, text="* 妖魔等级").grid(row=5, column=2, sticky='w', padx=5, pady=5)

        # 性别
        ttk.Label(basic_info_frame, text="性别:").grid(row=6, column=0, sticky='w', padx=5, pady=5)
        self.gender_var = tk.StringVar(value="男性")
        gender_combo = ttk.Combobox(basic_info_frame, textvariable=self.gender_var,
                                   values=["男性", "女性", "无性"], width=27, state="readonly")
        gender_combo.grid(row=6, column=1, padx=5, pady=5)
        ttk.Label(basic_info_frame, text="* 选择性别").grid(row=6, column=2, sticky='w', padx=5, pady=5)

        # 年龄
        ttk.Label(basic_info_frame, text="年龄:").grid(row=7, column=0, sticky='w', padx=5, pady=5)
        self.age_spinbox = ttk.Spinbox(basic_info_frame, from_=1, to=10000, width=28)
        self.age_spinbox.grid(row=7, column=1, padx=5, pady=5)
        ttk.Label(basic_info_frame, text="* 妖魔年龄").grid(row=7, column=2, sticky='w', padx=5, pady=5)

        # 态度
        ttk.Label(basic_info_frame, text="态度:").grid(row=8, column=0, sticky='w', padx=5, pady=5)
        self.attitude_var = tk.StringVar(value="aggressive")
        attitude_combo = ttk.Combobox(basic_info_frame, textvariable=self.attitude_var,
                                    values=["aggressive", "peaceful"], width=27, state="readonly")
        attitude_combo.grid(row=8, column=1, padx=5, pady=5)
        ttk.Label(basic_info_frame, text="* aggressive=攻击性, peaceful=和平").grid(row=8, column=2, sticky='w', padx=5, pady=5)

    def create_attributes_section(self, parent):
        """创建属性配置区域"""
        # 基础四维属性
        basic_attr_frame = ttk.LabelFrame(parent, text="基础四维属性", padding="10")
        basic_attr_frame.pack(fill='x', padx=10, pady=10)

        # 臂力
        ttk.Label(basic_attr_frame, text="臂力(str):").grid(row=0, column=0, sticky='w', padx=5, pady=5)
        self.str_spinbox = ttk.Spinbox(basic_attr_frame, from_=1, to=100, width=20)
        self.str_spinbox.grid(row=0, column=1, padx=5, pady=5)
        ttk.Label(basic_attr_frame, text="影响物理攻击").grid(row=0, column=2, sticky='w', padx=5, pady=5)

        # 悟性
        ttk.Label(basic_attr_frame, text="悟性(int):").grid(row=0, column=3, sticky='w', padx=5, pady=5)
        self.int_spinbox = ttk.Spinbox(basic_attr_frame, from_=1, to=100, width=20)
        self.int_spinbox.grid(row=0, column=4, padx=5, pady=5)
        ttk.Label(basic_attr_frame, text="影响精神攻击").grid(row=0, column=5, sticky='w', padx=5, pady=5)

        # 根骨
        ttk.Label(basic_attr_frame, text="根骨(con):").grid(row=1, column=0, sticky='w', padx=5, pady=5)
        self.con_spinbox = ttk.Spinbox(basic_attr_frame, from_=1, to=100, width=20)
        self.con_spinbox.grid(row=1, column=1, padx=5, pady=5)
        ttk.Label(basic_attr_frame, text="影响生命值").grid(row=1, column=2, sticky='w', padx=5, pady=5)

        # 身法
        ttk.Label(basic_attr_frame, text="身法(dex):").grid(row=1, column=3, sticky='w', padx=5, pady=5)
        self.dex_spinbox = ttk.Spinbox(basic_attr_frame, from_=1, to=100, width=20)
        self.dex_spinbox.grid(row=1, column=4, padx=5, pady=5)
        ttk.Label(basic_attr_frame, text="影响闪避").grid(row=1, column=5, sticky='w', padx=5, pady=5)

        # 战斗属性
        combat_attr_frame = ttk.LabelFrame(parent, text="战斗属性", padding="10")
        combat_attr_frame.pack(fill='x', padx=10, pady=10)

        # 气血
        ttk.Label(combat_attr_frame, text="气血(qi):").grid(row=0, column=0, sticky='w', padx=5, pady=5)
        self.qi_spinbox = ttk.Spinbox(combat_attr_frame, from_=100, to=1000000, increment=1000, width=20)
        self.qi_spinbox.grid(row=0, column=1, padx=5, pady=5)
        ttk.Label(combat_attr_frame, text="基础值: 等级×5000").grid(row=0, column=2, sticky='w', padx=5, pady=5)

        # 精神
        ttk.Label(combat_attr_frame, text="精神(jing):").grid(row=0, column=3, sticky='w', padx=5, pady=5)
        self.jing_spinbox = ttk.Spinbox(combat_attr_frame, from_=100, to=100000, increment=100, width=20)
        self.jing_spinbox.grid(row=0, column=4, padx=5, pady=5)
        ttk.Label(combat_attr_frame, text="基础值: 等级×500").grid(row=0, column=5, sticky='w', padx=5, pady=5)

        # 内力
        ttk.Label(combat_attr_frame, text="内力(neili):").grid(row=1, column=0, sticky='w', padx=5, pady=5)
        self.neili_spinbox = ttk.Spinbox(combat_attr_frame, from_=100, to=50000, increment=100, width=20)
        self.neili_spinbox.grid(row=1, column=1, padx=5, pady=5)
        ttk.Label(combat_attr_frame, text="基础值: 等级×100").grid(row=1, column=2, sticky='w', padx=5, pady=5)

        # 加力
        ttk.Label(combat_attr_frame, text="加力(jiali):").grid(row=1, column=3, sticky='w', padx=5, pady=5)
        self.jiali_spinbox = ttk.Spinbox(combat_attr_frame, from_=10, to=1000, increment=10, width=20)
        self.jiali_spinbox.grid(row=1, column=4, padx=5, pady=5)
        ttk.Label(combat_attr_frame, text="基础值: 等级×10").grid(row=1, column=5, sticky='w', padx=5, pady=5)

        # 基础技能
        skills_frame = ttk.LabelFrame(parent, text="基础技能", padding="10")
        skills_frame.pack(fill='x', padx=10, pady=10)

        ttk.Label(skills_frame, text="内功(force):").grid(row=0, column=0, sticky='w', padx=5, pady=5)
        self.force_spinbox = ttk.Spinbox(skills_frame, from_=1, to=1000, width=20)
        self.force_spinbox.grid(row=0, column=1, padx=5, pady=5)
        ttk.Label(skills_frame, text="默认值: 等级×10").grid(row=0, column=2, sticky='w', padx=5, pady=5)

        ttk.Label(skills_frame, text="轻功(dodge):").grid(row=0, column=3, sticky='w', padx=5, pady=5)
        self.dodge_spinbox = ttk.Spinbox(skills_frame, from_=1, to=1000, width=20)
        self.dodge_spinbox.grid(row=0, column=4, padx=5, pady=5)
        ttk.Label(skills_frame, text="默认值: 等级×10").grid(row=0, column=5, sticky='w', padx=5, pady=5)

        ttk.Label(skills_frame, text="招架(parry):").grid(row=1, column=0, sticky='w', padx=5, pady=5)
        self.parry_spinbox = ttk.Spinbox(skills_frame, from_=1, to=1000, width=20)
        self.parry_spinbox.grid(row=1, column=1, padx=5, pady=5)
        ttk.Label(skills_frame, text="默认值: 等级×10").grid(row=1, column=2, sticky='w', padx=5, pady=5)

        # 自动计算按钮
        ttk.Button(skills_frame, text="根据等级自动计算",
                  command=self.auto_calculate_attributes).grid(row=1, column=4, columnspan=2, padx=5, pady=5)

    def create_skills_section(self, parent):
        """创建技能配置区域"""
        # 技能列表区域
        skills_list_frame = ttk.LabelFrame(parent, text="技能列表", padding="10")
        skills_list_frame.pack(fill='both', expand=True, padx=10, pady=10)

        # 技能列表显示
        self.skills_tree = ttk.Treeview(skills_list_frame, columns=('name', 'damage_type', 'priority', 'cooldown'), show='headings', height=8)
        self.skills_tree.heading('name', text='技能名称')
        self.skills_tree.heading('damage_type', text='伤害类型')
        self.skills_tree.heading('priority', text='优先级')
        self.skills_tree.heading('cooldown', text='冷却时间')

        self.skills_tree.column('name', width=150)
        self.skills_tree.column('damage_type', width=100)
        self.skills_tree.column('priority', width=80)
        self.skills_tree.column('cooldown', width=80)

        self.skills_tree.pack(side='left', fill='both', expand=True, padx=5, pady=5)

        # 滚动条
        skills_scrollbar = ttk.Scrollbar(skills_list_frame, orient='vertical', command=self.skills_tree.yview)
        skills_scrollbar.pack(side='right', fill='y')
        self.skills_tree.configure(yscrollcommand=skills_scrollbar.set)

        # 技能操作按钮
        skills_buttons_frame = ttk.Frame(parent)
        skills_buttons_frame.pack(fill='x', padx=10, pady=5)

        ttk.Button(skills_buttons_frame, text="添加技能", command=self.add_skill).pack(side='left', padx=5)
        ttk.Button(skills_buttons_frame, text="编辑技能", command=self.edit_skill).pack(side='left', padx=5)
        ttk.Button(skills_buttons_frame, text="删除技能", command=self.delete_skill).pack(side='left', padx=5)
        ttk.Button(skills_buttons_frame, text="清空技能", command=self.clear_skills).pack(side='left', padx=5)

    def create_drops_section(self, parent):
        """创建掉落配置区域"""
        # 经验和潜能
        exp_potential_frame = ttk.LabelFrame(parent, text="基础奖励", padding="10")
        exp_potential_frame.pack(fill='x', padx=10, pady=10)

        ttk.Label(exp_potential_frame, text="经验值:").grid(row=0, column=0, sticky='w', padx=5, pady=5)
        self.exp_spinbox = ttk.Spinbox(exp_potential_frame, from_=0, to=10000000, increment=1000, width=20)
        self.exp_spinbox.grid(row=0, column=1, padx=5, pady=5)

        ttk.Label(exp_potential_frame, text="潜能:").grid(row=0, column=2, sticky='w', padx=5, pady=5)
        self.potential_spinbox = ttk.Spinbox(exp_potential_frame, from_=0, to=1000000, increment=100, width=20)
        self.potential_spinbox.grid(row=0, column=3, padx=5, pady=5)

        # 物品掉落
        items_frame = ttk.LabelFrame(parent, text="物品掉落", padding="10")
        items_frame.pack(fill='both', expand=True, padx=10, pady=10)

        # 物品列表显示
        self.items_tree = ttk.Treeview(items_frame, columns=('name', 'path', 'chance', 'amount'), show='headings', height=8)
        self.items_tree.heading('name', text='物品名称')
        self.items_tree.heading('path', text='文件路径')
        self.items_tree.heading('chance', text='掉落概率(%)')
        self.items_tree.heading('amount', text='数量')

        self.items_tree.column('name', width=120)
        self.items_tree.column('path', width=300)
        self.items_tree.column('chance', width=100)
        self.items_tree.column('amount', width=80)

        self.items_tree.pack(side='left', fill='both', expand=True, padx=5, pady=5)

        # 滚动条
        items_scrollbar = ttk.Scrollbar(items_frame, orient='vertical', command=self.items_tree.yview)
        items_scrollbar.pack(side='right', fill='y')
        self.items_tree.configure(yscrollcommand=items_scrollbar.set)

        # 物品操作按钮
        items_buttons_frame = ttk.Frame(parent)
        items_buttons_frame.pack(fill='x', padx=10, pady=5)

        ttk.Button(items_buttons_frame, text="添加物品", command=self.add_item).pack(side='left', padx=5)
        ttk.Button(items_buttons_frame, text="编辑物品", command=self.edit_item).pack(side='left', padx=5)
        ttk.Button(items_buttons_frame, text="删除物品", command=self.delete_item).pack(side='left', padx=5)
        ttk.Button(items_buttons_frame, text="清空物品", command=self.clear_items).pack(side='left', padx=5)

    def create_output_tab(self):
        """创建输出标签页"""
        output_frame = ttk.Frame(self.notebook)
        self.notebook.add(output_frame, text="预览与输出")

        # 文件保存路径
        path_frame = ttk.LabelFrame(output_frame, text="保存路径", padding="10")
        path_frame.pack(fill='x', padx=10, pady=10)

        ttk.Label(path_frame, text="保存路径:").pack(side='left', padx=5)
        self.path_entry = ttk.Entry(path_frame, width=60)
        self.path_entry.pack(side='left', padx=5, fill='x', expand=True)
        self.path_entry.insert(0, self.default_save_path)

        ttk.Button(path_frame, text="浏览", command=self.browse_folder).pack(side='left', padx=5)

        # JSON预览
        preview_frame = ttk.LabelFrame(output_frame, text="JSON预览", padding="10")
        preview_frame.pack(fill='both', expand=True, padx=10, pady=10)

        # 创建文本框和滚动条
        text_frame = ttk.Frame(preview_frame)
        text_frame.pack(fill='both', expand=True)

        self.preview_text = tk.Text(text_frame, wrap='none', font=('Consolas', 10))
        self.preview_text.pack(side='left', fill='both', expand=True)

        preview_scrollbar_y = ttk.Scrollbar(text_frame, orient='vertical', command=self.preview_text.yview)
        preview_scrollbar_y.pack(side='right', fill='y')
        self.preview_text.configure(yscrollcommand=preview_scrollbar_y.set)

        preview_scrollbar_x = ttk.Scrollbar(preview_frame, orient='horizontal', command=self.preview_text.xview)
        preview_scrollbar_x.pack(side='bottom', fill='x')
        self.preview_text.configure(xscrollcommand=preview_scrollbar_x.set)

        # 更新预览按钮
        ttk.Button(preview_frame, text="更新预览", command=self.update_preview).pack(pady=5)

    def create_bottom_buttons(self):
        """创建底部按钮"""
        bottom_frame = ttk.Frame(self.root)
        bottom_frame.pack(fill='x', padx=10, pady=10)

        ttk.Button(bottom_frame, text="生成JSON文件", command=self.generate_json).pack(side='right', padx=5)
        ttk.Button(bottom_frame, text="预览", command=self.update_preview).pack(side='right', padx=5)
        ttk.Button(bottom_frame, text="重置", command=self.reset_form).pack(side='right', padx=5)
        ttk.Button(bottom_frame, text="加载示例", command=self.load_example).pack(side='right', padx=5)

    def init_default_data(self):
        """初始化默认数据"""
        # 设置默认值
        self.level_spinbox.set(10)
        self.age_spinbox.set(500)

        # 设置默认属性
        self.str_spinbox.set(30)
        self.int_spinbox.set(20)
        self.con_spinbox.set(35)
        self.dex_spinbox.set(25)

        # 设置默认战斗属性
        self.qi_spinbox.set(50000)
        self.jing_spinbox.set(5000)
        self.neili_spinbox.set(1000)
        self.jiali_spinbox.set(100)

        # 设置默认基础技能
        self.force_spinbox.set(100)
        self.dodge_spinbox.set(100)
        self.parry_spinbox.set(100)

        # 设置默认掉落
        self.exp_spinbox.set(100000)
        self.potential_spinbox.set(50000)

    def auto_calculate_attributes(self):
        """根据等级自动计算属性"""
        try:
            level = int(self.level_spinbox.get())

            # 基础技能 = 等级 × 10
            self.force_spinbox.set(level * 10)
            self.dodge_spinbox.set(level * 10)
            self.parry_spinbox.set(level * 10)

            # 战斗属性基础值
            self.qi_spinbox.set(level * 5000)
            self.jing_spinbox.set(level * 500)
            self.neili_spinbox.set(level * 100)
            self.jiali_spinbox.set(level * 10)

            messagebox.showinfo("自动计算", "已根据等级自动计算属性值！")
        except ValueError:
            messagebox.showerror("错误", "请输入有效的等级数值！")

    def browse_folder(self):
        """浏览文件夹"""
        folder_path = filedialog.askdirectory(initialdir=self.default_save_path)
        if folder_path:
            self.path_entry.delete(0, tk.END)
            self.path_entry.insert(0, folder_path)

    def add_skill(self):
        """添加技能"""
        skill_dialog = SkillDialog(self.root, "添加技能")
        if skill_dialog.result:
            self.skills_list.append(skill_dialog.result)
            self.update_skills_tree()

    def edit_skill(self):
        """编辑技能"""
        selected = self.skills_tree.selection()
        if not selected:
            messagebox.showwarning("警告", "请先选择要编辑的技能！")
            return

        index = self.skills_tree.index(selected[0])
        skill_dialog = SkillDialog(self.root, "编辑技能", self.skills_list[index])
        if skill_dialog.result:
            self.skills_list[index] = skill_dialog.result
            self.update_skills_tree()

    def delete_skill(self):
        """删除技能"""
        selected = self.skills_tree.selection()
        if not selected:
            messagebox.showwarning("警告", "请先选择要删除的技能！")
            return

        if messagebox.askyesno("确认", "确定要删除选中的技能吗？"):
            index = self.skills_tree.index(selected[0])
            del self.skills_list[index]
            self.update_skills_tree()

    def clear_skills(self):
        """清空技能"""
        if messagebox.askyesno("确认", "确定要清空所有技能吗？"):
            self.skills_list = []
            self.update_skills_tree()

    def update_skills_tree(self):
        """更新技能树"""
        # 清空现有项目
        for item in self.skills_tree.get_children():
            self.skills_tree.delete(item)

        # 添加技能
        for skill in self.skills_list:
            self.skills_tree.insert('', 'end', values=(
                skill['name'],
                skill['damage_type'],
                skill['priority'],
                skill['cooldown']
            ))

    def add_item(self):
        """添加物品"""
        item_dialog = ItemDialog(self.root, "添加物品")
        if item_dialog.result:
            self.drops_items.append(item_dialog.result)
            self.update_items_tree()

    def edit_item(self):
        """编辑物品"""
        selected = self.items_tree.selection()
        if not selected:
            messagebox.showwarning("警告", "请先选择要编辑的物品！")
            return

        index = self.items_tree.index(selected[0])
        item_dialog = ItemDialog(self.root, "编辑物品", self.drops_items[index])
        if item_dialog.result:
            self.drops_items[index] = item_dialog.result
            self.update_items_tree()

    def delete_item(self):
        """删除物品"""
        selected = self.items_tree.selection()
        if not selected:
            messagebox.showwarning("警告", "请先选择要删除的物品！")
            return

        if messagebox.askyesno("确认", "确定要删除选中的物品吗？"):
            index = self.items_tree.index(selected[0])
            del self.drops_items[index]
            self.update_items_tree()

    def clear_items(self):
        """清空物品"""
        if messagebox.askyesno("确认", "确定要清空所有物品吗？"):
            self.drops_items = []
            self.update_items_tree()

    def update_items_tree(self):
        """更新物品树"""
        # 清空现有项目
        for item in self.items_tree.get_children():
            self.items_tree.delete(item)

        # 添加物品
        for item in self.drops_items:
            self.items_tree.insert('', 'end', values=(
                item['name'],
                item['path'],
                item['chance'],
                item['amount']
            ))

    def collect_data(self) -> Dict[str, Any]:
        """收集表单数据"""
        # 基础信息
        name_ids = [line.strip() for line in self.name_ids_text.get('1.0', 'end').strip().split('\n') if line.strip()]

        data = {
            'id': self.id_entry.get().strip(),
            'name': self.name_entry.get().strip(),
            'name_id': name_ids,
            'title': self.title_entry.get().strip(),
            'long': self.description_text.get('1.0', 'end').strip(),
            'level': int(self.level_spinbox.get()),
            'gender': self.gender_var.get(),
            'age': int(self.age_spinbox.get()),
            'attitude': self.attitude_var.get(),

            'base_attributes': {
                'str': int(self.str_spinbox.get()),
                'int': int(self.int_spinbox.get()),
                'con': int(self.con_spinbox.get()),
                'dex': int(self.dex_spinbox.get())
            },

            'combat_attributes': {
                'qi': int(self.qi_spinbox.get()),
                'jing': int(self.jing_spinbox.get()),
                'neili': int(self.neili_spinbox.get()),
                'jiali': int(self.jiali_spinbox.get())
            },

            'basic_skills': {
                'force': int(self.force_spinbox.get()),
                'dodge': int(self.dodge_spinbox.get()),
                'parry': int(self.parry_spinbox.get())
            },

            'skills': self.skills_list,

            'drops': {
                'exp': int(self.exp_spinbox.get()),
                'potential': int(self.potential_spinbox.get()),
                'items': self.drops_items
            }
        }

        return data

    def update_preview(self):
        """更新JSON预览"""
        try:
            data = self.collect_data()
            json_str = json.dumps(data, ensure_ascii=False, indent=2)

            self.preview_text.delete('1.0', 'end')
            self.preview_text.insert('1.0', json_str)

            # 自动切换到预览标签页
            self.notebook.select(1)  # 索引1是预览标签页
        except Exception as e:
            messagebox.showerror("错误", f"生成预览时出错：{str(e)}")

    def generate_json(self):
        """生成JSON文件"""
        try:
            # 验证必填字段
            if not self.validate_required_fields():
                return

            data = self.collect_data()

            # 确定保存路径
            save_path = self.path_entry.get().strip()
            if not save_path:
                save_path = self.default_save_path

            # 确保目录存在
            os.makedirs(save_path, exist_ok=True)

            # 生成文件名
            filename = f"{data['id']}.json"
            filepath = os.path.join(save_path, filename)

            # 保存文件
            with open(filepath, 'w', encoding='utf-8') as f:
                json.dump(data, f, ensure_ascii=False, indent=2)

            # 刷新配置文件列表
            self.refresh_config_list()

            messagebox.showinfo("成功", f"JSON文件已生成：\n{filepath}")

        except Exception as e:
            messagebox.showerror("错误", f"生成JSON文件时出错：{str(e)}")

    def validate_required_fields(self) -> bool:
        """验证必填字段"""
        errors = []

        if not self.id_entry.get().strip():
            errors.append("配置ID不能为空")

        if not self.name_entry.get().strip():
            errors.append("妖魔名称不能为空")

        name_ids = [line.strip() for line in self.name_ids_text.get('1.0', 'end').strip().split('\n') if line.strip()]
        if not name_ids:
            errors.append("名称ID列表不能为空")

        try:
            int(self.level_spinbox.get())
        except ValueError:
            errors.append("等级必须是有效数字")

        if errors:
            messagebox.showerror("验证错误", "\n".join(errors))
            return False

        return True

    def load_example(self):
        """加载示例数据"""
        # 基础信息
        self.id_entry.delete(0, tk.END)
        self.id_entry.insert(0, "yaomo_001")

        self.name_entry.delete(0, tk.END)
        self.name_entry.insert(0, "血魔")

        self.name_ids_text.delete('1.0', 'end')
        self.name_ids_text.insert('1.0', "xue mo\nxuemo\nmo")

        self.title_entry.delete(0, tk.END)
        self.title_entry.insert(0, "嗜血")

        self.description_text.delete('1.0', 'end')
        self.description_text.insert('1.0', "一只浑身散发着血腥气息的魔物,双眼猩红,獠牙毕露。\n它的身体仿佛被鲜血浸透,每一次呼吸都带着令人窒息的杀意。")

        self.level_spinbox.set(10)
        self.age_spinbox.set(500)

        # 示例技能
        self.skills_list = [
            {
                'id': 'xuemo_skill_001',
                'name': '血爆术',
                'description': '$N仰天长啸,浑身血气爆发,化作无数血刃向$n袭去!',
                'damage_type': 'perform',
                'base_damage': 10000,
                'damage_ratio': {'level': 100, 'str': 50},
                'cooldown': 3,
                'priority': 10,
                'condition': {'hp_percent': 100, 'enemy_count': 1}
            },
            {
                'id': 'xuemo_skill_002',
                'name': '血魔狂暴',
                'description': '$N双眼血光大盛,血色气息笼罩全场!',
                'damage_type': 'jing',
                'base_damage': 1000,
                'damage_ratio': {'level': 50, 'int': 30},
                'cooldown': 5,
                'priority': 8,
                'condition': {'hp_percent': 50, 'enemy_count': 1}
            }
        ]
        self.update_skills_tree()

        # 示例掉落物品
        self.drops_items = [
            {
                'path': '/clone/money/gold',
                'name': '黄金',
                'chance': 50,
                'amount': 1
            }
        ]
        self.update_items_tree()

        messagebox.showinfo("加载示例", "已加载血魔示例数据！")

    def reset_form(self):
        """重置表单"""
        if messagebox.askyesno("确认", "确定要重置所有数据吗？"):
            # 清空所有输入框
            self.id_entry.delete(0, tk.END)
            self.name_entry.delete(0, tk.END)
            self.name_ids_text.delete('1.0', 'end')
            self.title_entry.delete(0, tk.END)
            self.description_text.delete('1.0', 'end')

            # 重置为默认值
            self.init_default_data()

            # 清空列表
            self.skills_list = []
            self.drops_items = []
            self.update_skills_tree()
            self.update_items_tree()

            # 清空预览
            self.preview_text.delete('1.0', 'end')

    def create_new_config(self):
        """创建新配置"""
        # 清空所有输入框
        self.id_entry.delete(0, tk.END)
        self.name_entry.delete(0, tk.END)
        self.name_ids_text.delete('1.0', 'end')
        self.title_entry.delete(0, tk.END)
        self.description_text.delete('1.0', 'end')

        # 重置为默认值
        self.init_default_data()

        # 清空列表
        self.skills_list = []
        self.drops_items = []
        self.update_skills_tree()
        self.update_items_tree()

        # 清空预览
        self.preview_text.delete('1.0', 'end')

        # 重置窗口标题
        self.root.title("妖魔配置JSON文件生成器")

        # 切换到编辑标签页
        self.notebook.select(0)

    def refresh_config_list(self):
        """刷新配置文件列表"""
        # 清空现有列表
        for item in self.config_tree.get_children():
            self.config_tree.delete(item)

        # 检查配置目录是否存在
        if not os.path.exists(self.default_save_path):
            return

        # 扫描配置目录
        try:
            files = os.listdir(self.default_save_path)
            json_files = [f for f in files if f.endswith('.json')]

            for filename in sorted(json_files):
                filepath = os.path.join(self.default_save_path, filename)
                try:
                    with open(filepath, 'r', encoding='utf-8') as f:
                        data = json.load(f)
                        config_id = data.get('id', '')
                        name = data.get('name', '未知')
                        level = data.get('level', 0)

                        # 添加到列表，存储完整路径作为值
                        self.config_tree.insert('', 'end', values=(name, level), tags=(filepath,))
                except Exception as e:
                    print(f"加载配置文件失败 {filename}: {str(e)}")
                    continue

        except Exception as e:
            messagebox.showerror("错误", f"扫描配置目录失败：{str(e)}")

    def on_config_double_click(self, event):
        """双击配置列表项时加载配置"""
        self.load_selected_config()

    def load_selected_config(self):
        """加载选中的配置文件"""
        selected = self.config_tree.selection()
        if not selected:
            messagebox.showwarning("警告", "请先选择要加载的配置！")
            return

        # 获取文件路径
        item = selected[0]
        tags = self.config_tree.item(item, 'tags')
        if not tags:
            messagebox.showerror("错误", "无法获取配置文件路径！")
            return

        filepath = tags[0]

        try:
            with open(filepath, 'r', encoding='utf-8') as f:
                data = json.load(f)

            # 加载基础信息
            self.id_entry.delete(0, tk.END)
            self.id_entry.insert(0, data.get('id', ''))

            self.name_entry.delete(0, tk.END)
            self.name_entry.insert(0, data.get('name', ''))

            self.name_ids_text.delete('1.0', 'end')
            name_ids = data.get('name_id', [])
            if name_ids:
                self.name_ids_text.insert('1.0', '\n'.join(name_ids))

            self.title_entry.delete(0, tk.END)
            self.title_entry.insert(0, data.get('title', ''))

            self.description_text.delete('1.0', 'end')
            self.description_text.insert('1.0', data.get('long', ''))

            self.level_spinbox.set(data.get('level', 1))
            self.gender_var.set(data.get('gender', '男性'))
            self.age_spinbox.set(data.get('age', 100))
            self.attitude_var.set(data.get('attitude', 'aggressive'))

            # 加载基础属性
            base_attr = data.get('base_attributes', {})
            self.str_spinbox.set(base_attr.get('str', 30))
            self.int_spinbox.set(base_attr.get('int', 20))
            self.con_spinbox.set(base_attr.get('con', 35))
            self.dex_spinbox.set(base_attr.get('dex', 25))

            # 加载战斗属性
            combat_attr = data.get('combat_attributes', {})
            self.qi_spinbox.set(combat_attr.get('qi', 50000))
            self.jing_spinbox.set(combat_attr.get('jing', 5000))
            self.neili_spinbox.set(combat_attr.get('neili', 1000))
            self.jiali_spinbox.set(combat_attr.get('jiali', 100))

            # 加载基础技能
            basic_skills = data.get('basic_skills', {})
            self.force_spinbox.set(basic_skills.get('force', 100))
            self.dodge_spinbox.set(basic_skills.get('dodge', 100))
            self.parry_spinbox.set(basic_skills.get('parry', 100))

            # 加载技能列表
            self.skills_list = data.get('skills', [])
            self.update_skills_tree()

            # 加载掉落配置
            drops = data.get('drops', {})
            self.exp_spinbox.set(drops.get('exp', 100000))
            self.potential_spinbox.set(drops.get('potential', 50000))
            self.drops_items = drops.get('items', [])
            self.update_items_tree()

            # 更新窗口标题显示当前加载的配置
            self.root.title(f"妖魔配置JSON文件生成器 - 当前配置: {data.get('name', '未知')}")

        except Exception as e:
            messagebox.showerror("错误", f"加载配置文件失败：{str(e)}")

    def delete_selected_config(self):
        """删除选中的配置文件"""
        selected = self.config_tree.selection()
        if not selected:
            messagebox.showwarning("警告", "请先选择要删除的配置！")
            return

        # 获取文件路径
        item = selected[0]
        tags = self.config_tree.item(item, 'tags')
        if not tags:
            messagebox.showerror("错误", "无法获取配置文件路径！")
            return

        filepath = tags[0]
        filename = os.path.basename(filepath)

        if not messagebox.askyesno("确认删除", f"确定要删除配置文件 {filename} 吗？\n此操作不可恢复！"):
            return

        try:
            os.remove(filepath)
            self.refresh_config_list()
            messagebox.showinfo("成功", f"已删除配置文件：{filename}")
        except Exception as e:
            messagebox.showerror("错误", f"删除配置文件失败：{str(e)}")


    def run(self):
        """运行程序"""
        self.root.mainloop()


class SkillDialog:
    """技能配置对话框"""

    def __init__(self, parent, title: str, skill_data: Optional[Dict] = None):
        self.result = None

        self.dialog = tk.Toplevel(parent)
        self.dialog.title(title)
        self.dialog.geometry("650x600")
        self.dialog.resizable(True, True)
        self.dialog.transient(parent)
        self.dialog.grab_set()

        # 居中显示
        self.dialog.update_idletasks()
        x = (self.dialog.winfo_screenwidth() // 2) - (650 // 2)
        y = (self.dialog.winfo_screenheight() // 2) - (600 // 2)
        self.dialog.geometry(f"650x600+{x}+{y}")

        self.create_widgets(skill_data)

        # 等待对话框关闭
        self.dialog.wait_window()

    def create_widgets(self, skill_data: Optional[Dict]):
        """创建控件"""
        # 创建滚动区域
        canvas = tk.Canvas(self.dialog)
        scrollbar = ttk.Scrollbar(self.dialog, orient="vertical", command=canvas.yview)
        scrollable_frame = ttk.Frame(canvas)

        scrollable_frame.bind(
            "<Configure>",
            lambda e: canvas.configure(scrollregion=canvas.bbox("all"))
        )

        canvas.create_window((0, 0), window=scrollable_frame, anchor="nw")
        canvas.configure(yscrollcommand=scrollbar.set)

        # 绑定鼠标滚轮
        def _on_mousewheel(event):
            canvas.yview_scroll(int(-1*(event.delta/120)), "units")
        canvas.bind_all("<MouseWheel>", _on_mousewheel)

        # 基础信息
        basic_frame = ttk.LabelFrame(scrollable_frame, text="基础信息", padding="10")
        basic_frame.pack(fill='x', padx=10, pady=10)

        ttk.Label(basic_frame, text="技能ID:").grid(row=0, column=0, sticky='w', padx=5, pady=5)
        self.skill_id_entry = ttk.Entry(basic_frame, width=30)
        self.skill_id_entry.grid(row=0, column=1, padx=5, pady=5)

        ttk.Label(basic_frame, text="技能名称:").grid(row=0, column=2, sticky='w', padx=5, pady=5)
        self.skill_name_entry = ttk.Entry(basic_frame, width=30)
        self.skill_name_entry.grid(row=0, column=3, padx=5, pady=5)

        ttk.Label(basic_frame, text="伤害类型:").grid(row=1, column=0, sticky='w', padx=5, pady=5)
        self.damage_type_var = tk.StringVar(value="perform")
        damage_type_combo = ttk.Combobox(basic_frame, textvariable=self.damage_type_var,
                                       values=["perform", "ignore_armor", "jing"],
                                       width=28, state="readonly")
        damage_type_combo.grid(row=1, column=1, padx=5, pady=5)

        ttk.Label(basic_frame, text="基础伤害:").grid(row=1, column=2, sticky='w', padx=5, pady=5)
        self.base_damage_spinbox = ttk.Spinbox(basic_frame, from_=0, to=100000, increment=100, width=28)
        self.base_damage_spinbox.grid(row=1, column=3, padx=5, pady=5)

        # 伤害描述
        desc_frame = ttk.LabelFrame(scrollable_frame, text="技能描述", padding="10")
        desc_frame.pack(fill='x', padx=10, pady=10)

        ttk.Label(desc_frame, text="描述:").pack(anchor='w')
        self.description_text = tk.Text(desc_frame, height=3, width=70)
        self.description_text.pack(padx=5, pady=5)
        ttk.Label(desc_frame, text="支持 $N(施法者) 和 $n(目标) 变量").pack(anchor='w')

        # 伤害加成
        ratio_frame = ttk.LabelFrame(scrollable_frame, text="伤害加成比例", padding="10")
        ratio_frame.pack(fill='x', padx=10, pady=10)

        ttk.Label(ratio_frame, text="等级加成:").grid(row=0, column=0, sticky='w', padx=5, pady=5)
        self.level_ratio_spinbox = ttk.Spinbox(ratio_frame, from_=0, to=1000, width=20)
        self.level_ratio_spinbox.grid(row=0, column=1, padx=5, pady=5)

        ttk.Label(ratio_frame, text="臂力加成:").grid(row=0, column=2, sticky='w', padx=5, pady=5)
        self.str_ratio_spinbox = ttk.Spinbox(ratio_frame, from_=0, to=1000, width=20)
        self.str_ratio_spinbox.grid(row=0, column=3, padx=5, pady=5)

        ttk.Label(ratio_frame, text="悟性加成:").grid(row=1, column=0, sticky='w', padx=5, pady=5)
        self.int_ratio_spinbox = ttk.Spinbox(ratio_frame, from_=0, to=1000, width=20)
        self.int_ratio_spinbox.grid(row=1, column=1, padx=5, pady=5)

        ttk.Label(ratio_frame, text="根骨加成:").grid(row=1, column=2, sticky='w', padx=5, pady=5)
        self.con_ratio_spinbox = ttk.Spinbox(ratio_frame, from_=0, to=1000, width=20)
        self.con_ratio_spinbox.grid(row=1, column=3, padx=5, pady=5)

        ttk.Label(ratio_frame, text="身法加成:").grid(row=2, column=0, sticky='w', padx=5, pady=5)
        self.dex_ratio_spinbox = ttk.Spinbox(ratio_frame, from_=0, to=1000, width=20)
        self.dex_ratio_spinbox.grid(row=2, column=1, padx=5, pady=5)

        # 释放条件
        condition_frame = ttk.LabelFrame(scrollable_frame, text="释放条件", padding="10")
        condition_frame.pack(fill='x', padx=10, pady=10)

        ttk.Label(condition_frame, text="血量百分比(%):").grid(row=0, column=0, sticky='w', padx=5, pady=5)
        self.hp_percent_spinbox = ttk.Spinbox(condition_frame, from_=0, to=100, width=20)
        self.hp_percent_spinbox.grid(row=0, column=1, padx=5, pady=5)
        ttk.Label(condition_frame, text="达到此血量时可释放").grid(row=0, column=2, sticky='w', padx=5, pady=5)

        ttk.Label(condition_frame, text="最少敌人数量:").grid(row=1, column=0, sticky='w', padx=5, pady=5)
        self.enemy_count_spinbox = ttk.Spinbox(condition_frame, from_=1, to=10, width=20)
        self.enemy_count_spinbox.grid(row=1, column=1, padx=5, pady=5)
        ttk.Label(condition_frame, text="满足此敌人数量时可释放").grid(row=1, column=2, sticky='w', padx=5, pady=5)

        # 其他参数
        other_frame = ttk.LabelFrame(scrollable_frame, text="其他参数", padding="10")
        other_frame.pack(fill='x', padx=10, pady=10)

        ttk.Label(other_frame, text="优先级:").grid(row=0, column=0, sticky='w', padx=5, pady=5)
        self.priority_spinbox = ttk.Spinbox(other_frame, from_=1, to=20, width=20)
        self.priority_spinbox.grid(row=0, column=1, padx=5, pady=5)
        ttk.Label(other_frame, text="数值越高优先级越高").grid(row=0, column=2, sticky='w', padx=5, pady=5)

        ttk.Label(other_frame, text="冷却时间:").grid(row=1, column=0, sticky='w', padx=5, pady=5)
        self.cooldown_spinbox = ttk.Spinbox(other_frame, from_=1, to=60, width=20)
        self.cooldown_spinbox.grid(row=1, column=1, padx=5, pady=5)
        ttk.Label(other_frame, text="单位：心跳数(约2秒)").grid(row=1, column=2, sticky='w', padx=5, pady=5)

        # 按钮
        button_frame = ttk.Frame(scrollable_frame)
        button_frame.pack(fill='x', padx=10, pady=10)

        ttk.Button(button_frame, text="确定", command=self.ok_clicked).pack(side='right', padx=5)
        ttk.Button(button_frame, text="取消", command=self.cancel_clicked).pack(side='right', padx=5)

        # 打包canvas和scrollbar
        canvas.pack(side="left", fill="both", expand=True)
        scrollbar.pack(side="right", fill="y")

        # 如果有编辑数据，填充表单
        if skill_data:
            self.fill_form(skill_data)

    def fill_form(self, skill_data: Dict):
        """填充表单数据"""
        self.skill_id_entry.insert(0, skill_data.get('id', ''))
        self.skill_name_entry.insert(0, skill_data.get('name', ''))
        self.damage_type_var.set(skill_data.get('damage_type', 'perform'))
        self.base_damage_spinbox.set(skill_data.get('base_damage', 0))
        self.description_text.insert('1.0', skill_data.get('description', ''))

        damage_ratio = skill_data.get('damage_ratio', {})
        self.level_ratio_spinbox.set(damage_ratio.get('level', 0))
        self.str_ratio_spinbox.set(damage_ratio.get('str', 0))
        self.int_ratio_spinbox.set(damage_ratio.get('int', 0))
        self.con_ratio_spinbox.set(damage_ratio.get('con', 0))
        self.dex_ratio_spinbox.set(damage_ratio.get('dex', 0))

        condition = skill_data.get('condition', {})
        self.hp_percent_spinbox.set(condition.get('hp_percent', 100))
        self.enemy_count_spinbox.set(condition.get('enemy_count', 1))

        self.priority_spinbox.set(skill_data.get('priority', 1))
        self.cooldown_spinbox.set(skill_data.get('cooldown', 3))

    def collect_data(self) -> Dict:
        """收集表单数据"""
        damage_ratio = {}
        if self.level_ratio_spinbox.get() != '0':
            damage_ratio['level'] = int(self.level_ratio_spinbox.get())
        if self.str_ratio_spinbox.get() != '0':
            damage_ratio['str'] = int(self.str_ratio_spinbox.get())
        if self.int_ratio_spinbox.get() != '0':
            damage_ratio['int'] = int(self.int_ratio_spinbox.get())
        if self.con_ratio_spinbox.get() != '0':
            damage_ratio['con'] = int(self.con_ratio_spinbox.get())
        if self.dex_ratio_spinbox.get() != '0':
            damage_ratio['dex'] = int(self.dex_ratio_spinbox.get())

        data = {
            'id': self.skill_id_entry.get().strip(),
            'name': self.skill_name_entry.get().strip(),
            'description': self.description_text.get('1.0', 'end').strip(),
            'damage_type': self.damage_type_var.get(),
            'base_damage': int(self.base_damage_spinbox.get()),
            'damage_ratio': damage_ratio,
            'cooldown': int(self.cooldown_spinbox.get()),
            'priority': int(self.priority_spinbox.get()),
            'condition': {
                'hp_percent': int(self.hp_percent_spinbox.get()),
                'enemy_count': int(self.enemy_count_spinbox.get())
            }
        }

        return data

    def ok_clicked(self):
        """确定按钮点击"""
        if not self.skill_id_entry.get().strip():
            messagebox.showerror("错误", "技能ID不能为空！")
            return

        if not self.skill_name_entry.get().strip():
            messagebox.showerror("错误", "技能名称不能为空！")
            return

        self.result = self.collect_data()
        self.dialog.destroy()

    def cancel_clicked(self):
        """取消按钮点击"""
        self.dialog.destroy()


class ItemDialog:
    """物品配置对话框"""

    def __init__(self, parent, title: str, item_data: Optional[Dict] = None):
        self.result = None

        self.dialog = tk.Toplevel(parent)
        self.dialog.title(title)
        self.dialog.geometry("500x300")
        self.dialog.resizable(False, False)
        self.dialog.transient(parent)
        self.dialog.grab_set()

        # 居中显示
        self.dialog.update_idletasks()
        x = (self.dialog.winfo_screenwidth() // 2) - (500 // 2)
        y = (self.dialog.winfo_screenheight() // 2) - (300 // 2)
        self.dialog.geometry(f"500x300+{x}+{y}")

        self.create_widgets(item_data)

        # 等待对话框关闭
        self.dialog.wait_window()

    def create_widgets(self, item_data: Optional[Dict]):
        """创建控件"""
        # 物品信息
        info_frame = ttk.LabelFrame(self.dialog, text="物品信息", padding="10")
        info_frame.pack(fill='x', padx=10, pady=10)

        ttk.Label(info_frame, text="物品名称:").grid(row=0, column=0, sticky='w', padx=5, pady=5)
        self.item_name_entry = ttk.Entry(info_frame, width=40)
        self.item_name_entry.grid(row=0, column=1, padx=5, pady=5)

        ttk.Label(info_frame, text="文件路径:").grid(row=1, column=0, sticky='w', padx=5, pady=5)
        self.item_path_entry = ttk.Entry(info_frame, width=40)
        self.item_path_entry.grid(row=1, column=1, padx=5, pady=5)

        # 掉落设置
        drop_frame = ttk.LabelFrame(self.dialog, text="掉落设置", padding="10")
        drop_frame.pack(fill='x', padx=10, pady=10)

        ttk.Label(drop_frame, text="掉落概率(%):").grid(row=0, column=0, sticky='w', padx=5, pady=5)
        self.chance_spinbox = ttk.Spinbox(drop_frame, from_=0, to=100, width=20)
        self.chance_spinbox.grid(row=0, column=1, padx=5, pady=5)
        ttk.Label(drop_frame, text="0-100之间").grid(row=0, column=2, sticky='w', padx=5, pady=5)

        ttk.Label(drop_frame, text="掉落数量:").grid(row=1, column=0, sticky='w', padx=5, pady=5)
        self.amount_spinbox = ttk.Spinbox(drop_frame, from_=1, to=100, width=20)
        self.amount_spinbox.grid(row=1, column=1, padx=5, pady=5)
        ttk.Label(drop_frame, text="掉落的物品数量").grid(row=1, column=2, sticky='w', padx=5, pady=5)

        # 按钮
        button_frame = ttk.Frame(self.dialog)
        button_frame.pack(fill='x', padx=10, pady=10)

        ttk.Button(button_frame, text="确定", command=self.ok_clicked).pack(side='right', padx=5)
        ttk.Button(button_frame, text="取消", command=self.cancel_clicked).pack(side='right', padx=5)

        # 如果有编辑数据，填充表单
        if item_data:
            self.fill_form(item_data)

    def fill_form(self, item_data: Dict):
        """填充表单数据"""
        self.item_name_entry.insert(0, item_data.get('name', ''))
        self.item_path_entry.insert(0, item_data.get('path', ''))
        self.chance_spinbox.set(item_data.get('chance', 0))
        self.amount_spinbox.set(item_data.get('amount', 1))

    def collect_data(self) -> Dict:
        """收集表单数据"""
        data = {
            'name': self.item_name_entry.get().strip(),
            'path': self.item_path_entry.get().strip(),
            'chance': int(self.chance_spinbox.get()),
            'amount': int(self.amount_spinbox.get())
        }

        return data

    def ok_clicked(self):
        """确定按钮点击"""
        if not self.item_name_entry.get().strip():
            messagebox.showerror("错误", "物品名称不能为空！")
            return

        if not self.item_path_entry.get().strip():
            messagebox.showerror("错误", "文件路径不能为空！")
            return

        self.result = self.collect_data()
        self.dialog.destroy()

    def cancel_clicked(self):
        """取消按钮点击"""
        self.dialog.destroy()


def main():
    """主函数"""
    app = YaomoConfigGenerator()
    app.run()


if __name__ == "__main__":
    main()