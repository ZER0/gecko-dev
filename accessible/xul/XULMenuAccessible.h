/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef mozilla_a11y_XULMenuAccessible_h__
#define mozilla_a11y_XULMenuAccessible_h__

#include "AccessibleWrap.h"
#include "nsIDOMXULSelectCntrlEl.h"
#include "XULSelectControlAccessible.h"

namespace mozilla {
namespace a11y {

/**
 * Used for XUL menu, menuitem elements.
 */
class XULMenuitemAccessible : public AccessibleWrap
{
public:
  enum { eAction_Click = 0 };

  XULMenuitemAccessible(nsIContent* aContent, DocAccessible* aDoc);

  // Accessible
  virtual void Description(nsString& aDescription) MOZ_OVERRIDE;
  virtual a11y::role NativeRole() MOZ_OVERRIDE;
  virtual uint64_t NativeState() MOZ_OVERRIDE;
  virtual uint64_t NativeInteractiveState() const MOZ_OVERRIDE;
  virtual int32_t GetLevelInternal() MOZ_OVERRIDE;

  virtual bool CanHaveAnonChildren() MOZ_OVERRIDE;

  // ActionAccessible
  virtual uint8_t ActionCount() MOZ_OVERRIDE;
  virtual void ActionNameAt(uint8_t aIndex, nsAString& aName) MOZ_OVERRIDE;
  virtual bool DoAction(uint8_t aIndex) MOZ_OVERRIDE;
  virtual KeyBinding AccessKey() const MOZ_OVERRIDE;
  virtual KeyBinding KeyboardShortcut() const MOZ_OVERRIDE;

  // Widgets
  virtual bool IsActiveWidget() const MOZ_OVERRIDE;
  virtual bool AreItemsOperable() const MOZ_OVERRIDE;
  virtual Accessible* ContainerWidget() const MOZ_OVERRIDE;

protected:
  // Accessible
  virtual ENameValueFlag NativeName(nsString& aName) MOZ_OVERRIDE;
};

/**
 * Used for XUL menuseparator element.
 */
class XULMenuSeparatorAccessible : public XULMenuitemAccessible
{
public:
  XULMenuSeparatorAccessible(nsIContent* aContent, DocAccessible* aDoc);

  // Accessible
  virtual a11y::role NativeRole() MOZ_OVERRIDE;
  virtual uint64_t NativeState() MOZ_OVERRIDE;

  // ActionAccessible
  virtual uint8_t ActionCount() MOZ_OVERRIDE;
  virtual void ActionNameAt(uint8_t aIndex, nsAString& aName) MOZ_OVERRIDE;
  virtual bool DoAction(uint8_t aIndex) MOZ_OVERRIDE;

protected:
  // Accessible
  virtual ENameValueFlag NativeName(nsString& aName) MOZ_OVERRIDE;
};


/**
 * Used for XUL menupopup and panel.
 */
class XULMenupopupAccessible : public XULSelectControlAccessible
{
public:
  XULMenupopupAccessible(nsIContent* aContent, DocAccessible* aDoc);

  // Accessible
  virtual a11y::role NativeRole() MOZ_OVERRIDE;
  virtual uint64_t NativeState() MOZ_OVERRIDE;

  // Widgets
  virtual bool IsWidget() const MOZ_OVERRIDE;
  virtual bool IsActiveWidget() const MOZ_OVERRIDE;
  virtual bool AreItemsOperable() const MOZ_OVERRIDE;

  virtual Accessible* ContainerWidget() const MOZ_OVERRIDE;

protected:
  // Accessible
  virtual ENameValueFlag NativeName(nsString& aName) MOZ_OVERRIDE;
};

/**
 * Used for XUL menubar element.
 */
class XULMenubarAccessible : public AccessibleWrap
{
public:
  XULMenubarAccessible(nsIContent* aContent, DocAccessible* aDoc);

  // Accessible
  virtual a11y::role NativeRole() MOZ_OVERRIDE;

  // Widget
  virtual bool IsActiveWidget() const MOZ_OVERRIDE;
  virtual bool AreItemsOperable() const MOZ_OVERRIDE;
  virtual Accessible* CurrentItem() MOZ_OVERRIDE;
  virtual void SetCurrentItem(Accessible* aItem) MOZ_OVERRIDE;

protected:
  // Accessible
  virtual ENameValueFlag NativeName(nsString& aName) MOZ_OVERRIDE;
};

} // namespace a11y
} // namespace mozilla

#endif
