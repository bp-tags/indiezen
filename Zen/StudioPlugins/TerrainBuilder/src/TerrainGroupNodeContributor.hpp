//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Terrain Builder
//
// Copyright (C) 2001 - 2010 Tony Richards
// Copyright (C) 2008 - 2010 Matthew Alan Gray
//
// Licensed under the Games by Sarge Publishing License - See your licensing
// agreement for terms and conditions.
//
// Do not redistribute this source code.
//
// Tony Richards trichards@gamesbysarge.com
// Matthew Alan Gray mgray@indiezen.org
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
#ifndef TERRAINBUILDER_TERRAIN_GROUP_NODE_CONTRIBUTOR_HPP_INCLUDED
#define TERRAINBUILDER_TERRAIN_GROUP_NODE_CONTRIBUTOR_HPP_INCLUDED

#include <Zen/Core/Memory/managed_weak_ptr.hpp>

#include <Zen/Core/Utility/runtime_exception.hpp>

#include <Zen/Studio/Workbench/I_Workbench.hpp>
#include <Zen/Studio/Workbench/I_PropertiesHandle.hpp>
#include <Zen/Studio/Workbench/I_ExplorerNodeContributor.hpp>

#include <Zen/Studio/WorkbenchCommon/I_ExplorerNodeType.hpp>
#include <Zen/Studio/WorkbenchCommon/I_ExplorerNode.hpp>

#include <Zen/Studio/WorkbenchCommon/indirect_explorer_node_action.hpp>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace TerrainBuilder {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
class ContributorService;

class TerrainGroupNodeContributor
:   public Zen::Studio::Workbench::I_ExplorerNodeContributor
{
    /// @name Types
    /// @{
public:
    typedef Zen::Studio::Workbench::indirect_explorer_node_action<TerrainGroupNodeContributor>  NodeAction_type;
    typedef Zen::Studio::Workbench::I_ExplorerNode                                              I_ExplorerNode;
    /// @}

    /// @name I_ExplorerNodeContributor implementation
    /// @{
public:
    virtual void getExplorerNodeActions(I_ExplorerNode& _explorerNode, I_ExplorerNodeActionVisitor& _visitor);
    virtual void getExplorerNodeDecorations(I_ExplorerNode& _explorerNode, I_ExplorerNodeDecorationVisitor& _visitor);
    /// @}

    /// @name TerrainGroupNodeContributor implementation
    /// @{
public:
    /// Edit a Terrain Group.
    void open(Zen::Studio::Workbench::I_ExplorerNode& _selectedNode);

    /// Rename a Terrain Group.
    void rename(Zen::Studio::Workbench::I_ExplorerNode& _selectedNode);

    /// Add a Terrian Chunk to a Terrain Group.
    void addTerrainChunk(Zen::Studio::Workbench::I_ExplorerNode& _selectedNode);

    /// Focus
    /// Typically connected to I_ExplorerNode::onSelect
    void focus(Zen::Studio::Workbench::I_ExplorerNode* _pNode);

    /// Unfocus
    /// Typically connected to I_ExplorerNode::onDeselect
    void unfocus(Zen::Studio::Workbench::I_ExplorerNode* _pNode);
    /// @}

    /// @name 'Structors
    /// @{
public:
             TerrainGroupNodeContributor(ContributorService& _service);
    virtual ~TerrainGroupNodeContributor();
    /// @}

    /// @name Member Variables
    /// @{
private:
    ContributorService&                                 m_service;
    NodeAction_type                                     m_open;
    NodeAction_type                                     m_rename;
    NodeAction_type                                     m_addTerrainChunk;

    Zen::Studio::Workbench::I_Workbench::pPropertiesHandle_type    m_pPropertiesHandle;
    /// @}

};  // class TerrainGroupNodeContributor

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace TerrainBuilder
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif // TERRAINBUILDER_TERRAIN_GROUP_NODE_CONTRIBUTOR_HPP_INCLUDED
