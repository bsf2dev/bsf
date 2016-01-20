//********************************** Banshee Engine (www.banshee3d.com) **************************************************//
//**************** Copyright (c) 2016 Marko Pintera (marko.pintera@gmail.com). All rights reserved. **********************//
#pragma once

#include "BsEditorPrerequisites.h"
#include "BsGUISkin.h"
#include "BsModule.h"
#include "BsGUIContent.h"
#include "BsApplication.h"

namespace BansheeEngine
{
	/**
	 * @brief	Types of valid icons used when viewing the project library.
	 */
	enum class ProjectIcon
	{
		Folder, Mesh, Font, Texture, PlainText, ScriptCode, SpriteTexture, Shader, ShaderInclude, Material, Prefab, GUISkin
	};

	/**
	 * @brief	Types of icons that may be displayed on the tool bar.
	 */
	enum class ToolbarIcon
	{
		NewCamera, NewRenderable, NewPointLight, NewDirLight, NewSpotLight, NewSceneObject, NewCube, NewSphere, NewCone, 
		NewQuad, NewMat, NewCSScript, NewShader, NewSpriteTex, Pause, Play, Step, Undo, Redo, OpenProject, SaveProject, 
		SaveScene
	};

	/**
	 * @brief	Types of icons that may be displayed in the scene window.
	 */
	enum class SceneWindowIcon
	{
		View, Move, Rotate, Scale, Pivot, Center, Local, World, MoveSnap, RotateSnap
	};

	/**
	 * @brief	Types of icons that may be displayed in the inspector window.
	 */
	enum class InspectorWindowIcon
	{
		Create, Clone, Clear, Resize, Delete, MoveUp, MoveDown, Edit, Apply, Add, Cancel
	};

	/**
	 * @brief	Types of icons that may be displayed in the library window.
	 */
	enum class LibraryWindowIcon
	{
		Home, Up, Clear, Options
	};

	/**
	 * @brief	Types of icons used in various areas throughout the editor.
	 */
	enum class EditorIcon
	{
		XBtn
	};

	/**
	 * @brief	Types of icons to be used along with log messages depending on their severity.
	 */
	enum class LogMessageIcon
	{
		Info, Warning, Error
	};

	/**
	 * @brief	Contains a set of built-in resources used by the editor.
	 */
	class BS_ED_EXPORT BuiltinEditorResources : public BansheeEngine::Module<BuiltinEditorResources>
	{
	public:
		BuiltinEditorResources();
		~BuiltinEditorResources();

		/**
		 * @brief	Returns the default editor GUI skin.
		 */
		const HGUISkin& getSkin() const { return mSkin; }

		/** Returns the default font used by the editor. */
		const HFont& getDefaultFont() const { return mDefaultFont; }

		/**
		 * @brief	Creates a material used for docking drop overlay used by the editor.
		 */
		HMaterial createDockDropOverlayMaterial() const;

		/**
		 * @brief	Creates a material used for rendering the scene grid.
		 */
		HMaterial createSceneGridMaterial() const;

		/**
		 * @brief	Creates a material used for picking non-transparent objects in scene view.
		 */
		HMaterial createPicking(CullingMode cullMode) const;

		/**
		 * @brief	Creates a material used for picking transparent objects in scene view.
		 */
		HMaterial createPickingAlpha(CullingMode cullMode) const;

		/**
		 * @brief	Creates a material used for rendering wireframe gizmos.
		 */
		HMaterial createWireGizmoMat() const;

		/**
		 * @brief	Creates a material used for rendering solid gizmos.
		 */
		HMaterial createSolidGizmoMat() const;

		/**
		 * @brief	Creates a material used for rendering icon gizmos.
		 */
		HMaterial createIconGizmoMat() const;

		/**
		 * @brief	Creates a material used for picking non-transparent gizmos.
		 */
		HMaterial createGizmoPickingMat() const;

		/**
		 * @brief	Creates a material used for picking transparent gizmos.
		 */
		HMaterial createAlphaGizmoPickingMat() const;

		/**
		 * @brief	Creates a material used for rendering wireframe handles.
		 */
		HMaterial createWireHandleMat() const;

		/**
		 * @brief	Creates a material used for rendering solid handles.
		 */
		HMaterial createSolidHandleMat() const;

		/** Creates a material used for rendering text for gizmos and handles. */
		HMaterial createTextGizmoMat() const;

		/** Creates a material used for clearing the alpha channel of the handle rendering texture. */
		HMaterial createHandleClearAlphaMat() const;

		/**
		 * @brief	Creates a material used for displaying selected objects.
		 */
		HMaterial createSelectionMat() const;

		/**
		 * @brief	Retrieves an icon that represents a specific resource type
		 *			that may be displayed when viewing the project library.
		 */
		HSpriteTexture getLibraryIcon(ProjectIcon icon, int size) const;

		/**
		 * @brief	Retrieves an icon that may be displayed on the main window's toolbar.
		 */
		HSpriteTexture getToolbarIcon(ToolbarIcon icon) const;

		/**
		 * @brief	Retrieves an icon that may be displayed on the scene window.
		 */
		GUIContentImages getSceneWindowIcon(SceneWindowIcon icon) const;

		/**
		 * @brief	Retrieves an icon that may be displayed on the library window.
		 */
		HSpriteTexture getLibraryWindowIcon(LibraryWindowIcon icon) const;

		/**
		 * @brief	Retrieves an icon that may be displayed on the inspector window.
		 */
		HSpriteTexture getInspectorWindowIcon(InspectorWindowIcon icon) const;

		/**
		 * @brief	Retrieves an icon that represents a specific generic editor icon.
		 */
		HSpriteTexture getIcon(EditorIcon icon) const;

		/**
		 * @brief	Retrieves an icon that represents a specific log message type.
		 */
		HSpriteTexture getLogMessageIcon(LogMessageIcon icon, UINT32 size, bool dark) const;

		/**
		 * @brief	Returns text contained in the default "empty" shader.
		 */
		WString getEmptyShaderCode() const;

		/**
		 * @brief	Returns text contained in the default "empty" C# script.
		 */
		WString getEmptyCSScriptCode() const;

		/**
		 * @brief	Returns path to the builtin shader include folder, relative to the working directory.
		 */
		static Path getShaderIncludeFolder();

		/**
		 * @brief	Returns path to the default widget layout file, relative to the working directory.
		 */
		static Path getDefaultWidgetLayoutPath();

		static const String ObjectFieldStyleName;
		static const String ObjectFieldLabelStyleName;
		static const String ObjectFieldDropBtnStyleName;
		static const String ObjectFieldClearBtnStyleName;

		static const String TextureFieldStyleName;
		static const String TextureFieldLabelStyleName;
		static const String TextureFieldDropStyleName;
		static const String TextureFieldClearBtnStyleName;

	private:
		/**
		 * @brief	Imports all necessary resources and converts them to engine-ready format.
		 *
		 * @note	Normally you only want to use this during development phase and then ship
		 *			with engine-ready format only.
		 */
		void preprocess();

		/**
		 * @brief	Generates the default editor skin and all GUI element styles.
		 */
		GUISkinPtr generateGUISkin();

		/**
		 * @brief	Generates different sizes of resource icons. Expects maximum sizes of the icons to already be present.
		 * 			Resulting textures will be saved to the same directory the maximum size textures are in.
		 */
		void generateResourceIcons(const Path& inputFolder, const ResourceManifestPtr& resourceManifest);

		/**
		 * @brief	Loads a GUI skin texture with the specified filename.
		 */
		HSpriteTexture getGUITexture(const WString& name) const;

		/**
		 * @brief	Loads a GUI icon with the specified filename.
		 */
		HSpriteTexture getGUIIcon(const WString& name) const;

		/**
		 * @brief	Loads a shader with the specified filename
		 */
		HShader getShader(const WString& name) const;

		HShader mShaderDockOverlay;
		HShader mShaderSceneGrid;
		HShader mShaderPicking[3];
		HShader mShaderPickingAlpha[3];
		HShader mShaderGizmoSolid;
		HShader mShaderGizmoWire;
		HShader mShaderGizmoIcon;
		HShader mShaderGizmoPicking;
		HShader mShaderGizmoAlphaPicking;
		HShader mShaderGizmoText;
		HShader mShaderHandleSolid;
		HShader mShaderHandleWire;
		HShader mShaderHandleClearAlpha;
		HShader mShaderSelection;

		HFont mDefaultFont;
		HGUISkin mSkin;

		ResourceManifestPtr mResourceManifest;

		static const char* ShaderFolder;
		static const char* SkinFolder;
		static const char* IconFolder;
		static const char* ShaderIncludeFolder;

		Path BuiltinDataFolder;
		Path EditorSkinFolder;
		Path EditorIconFolder;
		Path EditorShaderFolder;
		Path EditorShaderIncludeFolder;

		Path BuiltinRawDataFolder;
		Path EditorRawSkinFolder;
		Path EditorRawShaderIncludeFolder;
		Path EditorRawShaderFolder;

		Path ResourceManifestPath;

		static const WString DefaultFontFilename;
		static const WString DefaultAAFontFilename;
		static const UINT32 DefaultFontSize;
		static const UINT32 TitleFontSize;

		static const Color TextNormalColor;
		static const Color TextActiveColor;

		static const WString GUISkinFile;

		static const WString FolderIconTex;
		static const WString MeshIconTex;
		static const WString TextureIconTex;
		static const WString FontIconTex;
		static const WString PlainTextIconTex;
		static const WString ScriptCodeIconTex;
		static const WString ShaderIconTex;
		static const WString ShaderIncludeIconTex;
		static const WString MaterialIconTex;
		static const WString SpriteTextureIconTex;
		static const WString PrefabIconTex;
		static const WString GUISkinIconTex;

		static const WString WindowBackgroundTex;

		static const WString WindowFrameNormal;
		static const WString WindowFrameFocused;

		static const WString TabBarBackgroundTex;
		static const WString TitleBarBackgroundTex;

		static const WString CloseButtonNormalTex;
		static const WString CloseButtonHoverTex;
		static const WString CloseButtonActiveTex;

		static const WString MinButtonNormalTex;
		static const WString MinButtonHoverTex;
		static const WString MinButtonActiveTex;

		static const WString MaxButtonNormalTex;
		static const WString MaxButtonHoverTex;
		static const WString MaxButtonActiveTex;

		static const WString TabButtonNormalTex;
		static const WString TabButtonFocusedTex;

		static const WString ButtonNormalTex;
		static const WString ButtonHoverTex;
		static const WString ButtonActiveTex;

		static const WString ButtonLeftNormalTex;
		static const WString ButtonLeftHoverTex;
		static const WString ButtonLeftActiveTex;

		static const WString ButtonRightNormalTex;
		static const WString ButtonRightHoverTex;
		static const WString ButtonRightActiveTex;

		static const WString ToggleNormalTex;
		static const WString ToggleHoverTex;
		static const WString ToggleNormalOnTex;
		static const WString ToggleHoverOnTex;

		static const WString ObjectDropBtnNormalTex;
		static const WString ObjectDropBtnNormalOnTex;
		static const WString ObjectClearBtnNormalTex;
		static const WString ObjectClearBtnHoverTex;
		static const WString ObjectClearBtnActiveTex;

		static const WString SliderHBackgroundTex;
		static const WString SliderHFillTex;
		static const WString SliderVBackgroundTex;
		static const WString SliderVFillTex;
		static const WString SliderHandleNormalTex;
		static const WString SliderHandleHoverTex;
		static const WString SliderHandleActiveTex;

		static const WString FoldoutOpenNormalTex;
		static const WString FoldoutOpenHoverTex;
		static const WString FoldoutOpenActiveTex;
		static const WString FoldoutClosedNormalTex;
		static const WString FoldoutClosedHoverTex;
		static const WString FoldoutClosedActiveTex;

		static const WString InputBoxNormalTex;
		static const WString InputBoxHoverTex;
		static const WString InputBoxFocusedTex;

		static const WString ScrollBarUpNormalTex;
		static const WString ScrollBarUpHoverTex;
		static const WString ScrollBarUpActiveTex;

		static const WString ScrollBarDownNormalTex;
		static const WString ScrollBarDownHoverTex;
		static const WString ScrollBarDownActiveTex;

		static const WString ScrollBarLeftNormalTex;
		static const WString ScrollBarLeftHoverTex;
		static const WString ScrollBarLeftActiveTex;

		static const WString ScrollBarRightNormalTex;
		static const WString ScrollBarRightHoverTex;
		static const WString ScrollBarRightActiveTex;

		static const WString ScrollBarHandleHorzNormalTex;
		static const WString ScrollBarHandleHorzHoverTex;
		static const WString ScrollBarHandleHorzActiveTex;

		static const WString ScrollBarHandleVertNormalTex;
		static const WString ScrollBarHandleVertHoverTex;
		static const WString ScrollBarHandleVertActiveTex;

		static const WString ScrollBarHBgTex;
		static const WString ScrollBarVBgTex;

		static const WString DropDownBtnNormalTex;
		static const WString DropDownBtnHoverTex;
		static const WString DropDownBtnActiveTex;

		static const WString DropDownBoxBgTex;
		static const WString DropDownBoxSideBgTex;
		static const WString DropDownBoxHandleTex;

		static const WString DropDownBoxEntryNormalTex;
		static const WString DropDownBoxEntryHoverTex;

		static const WString DropDownBoxEntryToggleNormalTex;
		static const WString DropDownBoxEntryToggleHoverTex;
		static const WString DropDownBoxEntryToggleNormalOnTex;
		static const WString DropDownBoxEntryToggleHoverOnTex;

		static const WString DropDownBoxBtnUpNormalTex;
		static const WString DropDownBoxBtnUpHoverTex;

		static const WString DropDownBoxBtnDownNormalTex;
		static const WString DropDownBoxBtnDownHoverTex;

		static const WString DropDownBoxEntryExpNormalTex;
		static const WString DropDownBoxEntryExpHoverTex;

		static const WString DropDownSeparatorTex;

		static const WString MenuBarBgTex;
		static const WString MenuBarBansheeLogoTex;

		static const WString MenuBarBtnNormalTex;
		static const WString MenuBarBtnHoverTex;
		static const WString MenuBarBtnActiveTex;

		static const WString MenuBarLineNormalTex;
		static const WString MenuBarLineActiveTex;

		static const WString ToolBarBtnNormalTex;
		static const WString ToolBarBtnHoverTex;
		static const WString ToolBarBtnActiveTex;

		static const WString ToolBarSeparatorTex;

		static const WString DockSliderNormalTex;

		static const WString TreeViewExpandButtonOffNormal;
		static const WString TreeViewExpandButtonOffHover;
		static const WString TreeViewExpandButtonOnNormal;
		static const WString TreeViewExpandButtonOnHover;

		static const WString TreeViewHighlightBackground;
		static const WString TreeViewEditBox;

		static const WString TreeViewElementHighlight;
		static const WString TreeViewElementSepHighlight;

		static const WString ColorPickerSliderHorzHandleTex;
		static const WString ColorPickerSliderVertHandleTex;
		static const WString ColorPickerSlider2DHandleTex;

		static const WString ProgressBarFillTex;
		static const WString ProgressBarBgTex;

		static const WString SelectionAreaTex;
		static const WString SelectionBgTex;

		static const WString TextureDropTex;
		static const WString TextureDropOnTex;

		static const WString XButtonNormalTex;
		static const WString XButtonHoverTex;
		static const WString XButtonActiveTex;

		static const WString StatusBarBgTex;
		static const WString ScrollAreaBgTex;

		static const WString InspectorTitleBgTex;
		static const WString InspectorContentBgTex;
		static const WString InspectorContentBgAlternateTex;

		static const WString ShaderDockOverlayFile;
		static const WString ShaderSceneGridFile;
		static const WString ShaderPickingCullNoneFile;
		static const WString ShaderPickingCullCWFile;
		static const WString ShaderPickingCullCCWFile;
		static const WString ShaderPickingAlphaCullNoneFile;
		static const WString ShaderPickingAlphaCullCWFile;
		static const WString ShaderPickingAlphaCullCCWFile;
		static const WString ShaderWireGizmoFile;
		static const WString ShaderSolidGizmoFile;
		static const WString ShaderWireHandleFile;
		static const WString ShaderSolidHandleFile;
		static const WString ShaderHandleClearAlphaFile;
		static const WString ShaderIconGizmoFile;
		static const WString ShaderGizmoPickingFile;
		static const WString ShaderGizmoPickingAlphaFile;
		static const WString ShaderTextGizmoFile;
		static const WString ShaderSelectionFile;

		static const WString EmptyShaderCodeFile;
		static const WString EmptyCSScriptCodeFile;
	};
}